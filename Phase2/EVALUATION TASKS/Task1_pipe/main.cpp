#include <iostream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>
#include <string>

using namespace std;

class Vaccination {
private:
    string VaccinationId;
    int DoseAdministered;
public:
    Vaccination(string id, int dose) : VaccinationId(id), DoseAdministered(dose) {}

    string getVaccinationId() const { return VaccinationId; }
    int getDoseAdministered() const { return DoseAdministered; }
};

void client(int write_to_server, int read_from_server) {
    vector<Vaccination> vacc = {
        Vaccination("P001", 4), 
        Vaccination("P002", 5), 
        Vaccination("P003", 6), 
        Vaccination("P004", 15), 
        Vaccination("P005", 1)
    };

    int size = vacc.size();
    int arr[100];

    // Filling the array with dose data
    for (int i = 0; i < size; ++i) {
        arr[i] = vacc[i].getDoseAdministered();
    }

    cout << "Client sending doses: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Send data to server
    write(write_to_server, &size, sizeof(size));
    write(write_to_server, arr, sizeof(int) * size);

    // Read result from server
    int sum;
    read(read_from_server, &sum, sizeof(sum));
    cout << "Client received sum from server: " << sum << endl;

    close(write_to_server);
    close(read_from_server);
}

void server(int read_from_client, int write_to_client) {
    int buffer[100];
    int size;
    int sum = 0;

    // Read size and data from client
    read(read_from_client, &size, sizeof(size));
    read(read_from_client, buffer, sizeof(int) * size);

    cout << "Server received doses: ";
    for (int i = 0; i < size; ++i) {
        cout << buffer[i] << " ";
        sum += buffer[i];
    }
    cout << endl;

    cout << "Server calculated sum: " << sum << endl;

    // Send sum back to client
    write(write_to_client, &sum, sizeof(sum));

    close(read_from_client);
    close(write_to_client);
}

int main() {
    int pipe_client_to_server[2];
    int pipe_server_to_client[2];

    // Create pipes
    if (pipe(pipe_client_to_server) == -1 || pipe(pipe_server_to_client) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {  // Child process (Client)
        close(pipe_client_to_server[0]);
        close(pipe_server_to_client[1]);
        client(pipe_client_to_server[1], pipe_server_to_client[0]);
        exit(0);
    } else {  // Parent process (Server)
        close(pipe_client_to_server[1]);
        close(pipe_server_to_client[0]);
        server(pipe_client_to_server[0], pipe_server_to_client[1]);
        wait(nullptr);  // Wait for child process
    }

    return 0;
}
