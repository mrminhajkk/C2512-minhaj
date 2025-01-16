#include <iostream>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <cstring>
#include <vector>

#define SHM_KEY 1234

class Vaccination {
public:
    std::string VaccinationId;
    int DoseAdministered;

    Vaccination(std::string id, int dose) : VaccinationId(id), DoseAdministered(dose) {}

    std::string getVaccinationId() const { return VaccinationId; }
    int getDoseAdministered() const { return DoseAdministered; }
};

struct SharedMemory {
    int doses[5];
    int sum;
    bool dataReady;       // Flag to indicate that the client has written data
    bool serverDone;      // Flag to indicate that the server has calculated the sum
};

void client(int& shmid) { // Child 1 (Client)
    SharedMemory* sharedMem = (SharedMemory*)shmat(shmid, nullptr, 0);

    // Prepare the array of doses to send to the server
    std::vector<Vaccination> vacc = {
        Vaccination("P001", 4),
        Vaccination("P002", 5),
        Vaccination("P003", 6),
        Vaccination("P004", 15),
        Vaccination("P005", 1)
    };

    // Send doses to shared memory
    for (int i = 0; i < 5; ++i) {
        sharedMem->doses[i] = vacc[i].getDoseAdministered();
    }

    std::cout << "Client sent doses: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << sharedMem->doses[i] << " ";
    }
    std::cout << std::endl;

    // Set dataReady flag to indicate that the client is done writing
    sharedMem->dataReady = true;

    // Wait for the server to finish calculating the sum
    while (!sharedMem->serverDone) {
        sleep(1);  // Wait for the server to finish
    }

    // Now the client can read the sum calculated by the server
    std::cout << "Client received sum from server: " << sharedMem->sum << std::endl;

    shmdt(sharedMem);
}

void server(int& shmid) { // Child 2 (Server)
    SharedMemory* sharedMem = (SharedMemory*)shmat(shmid, nullptr, 0);

    // Wait until the client has finished writing data
    while (!sharedMem->dataReady) {
        sleep(1);  // Wait for the client to write data
    }

    // Receiving doses from the client (shared memory)
    std::cout << "Server received doses: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << sharedMem->doses[i] << " ";
    }
    std::cout << std::endl;

    // Calculate the sum of the doses
    sharedMem->sum = 0;
    for (int i = 0; i < 5; ++i) {
        sharedMem->sum += sharedMem->doses[i];
    }

    std::cout << "Server calculated sum: " << sharedMem->sum << std::endl;

    // Set serverDone flag to indicate the sum is ready
    sharedMem->serverDone = true;

    shmdt(sharedMem);
}

int main() {
    // Allocate shared memory
    int shmid = shmget(SHM_KEY, sizeof(SharedMemory), 0666 | IPC_CREAT);

    if (shmid == -1) {
        std::cerr << "Shared memory allocation failed!" << std::endl;
        return 1;
    }

    pid_t pid = fork();
    if (pid == 0) {
        // Server process (Child 2)
        server(shmid);
        shmctl(shmid, IPC_RMID, nullptr);  // Cleanup shared memory
        return 0;
    }

    // Delay to ensure server waits for client to write data
    sleep(1);

    pid = fork();
    if (pid == 0) {
        // Client process (Child 1)
        client(shmid);
        return 0;
    }

    // Parent process waits for both children to finish
    wait(nullptr);
    wait(nullptr);

    return 0;
}
