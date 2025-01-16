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

    for (int i = 0; i < size; ++i) {
        arr[i] = vacc[i].getDoseAdministered();
    }

    cout << "Client sending doses: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    write(write_to_server, arr, sizeof(int) * size);

    int sum;
    read(read_from_server, &sum, sizeof(sum));
    cout << "Client received sum from server: " << sum << endl;

    close(write_to_server);
    close(read_from_server);
}

void server(int read_from_client, int write_to_client) {
    int buffer[100];
    int size = 0;

    read(read_from_client, buffer, sizeof(buffer));
    
    while (buffer[size] != 0 && size < 100) {
        size++;
    }
    // for(size=0 ; size< 100; size++){
    //     size++;
    // if(buffer[size]==0){
    //     break;
    // }
    // size = sizeof(buffer) / sizeof(int);
    // }

    cout << "Server received doses: ";
    for (int i = 0; i < size; ++i) {
        cout << buffer[i] << " ";
    }
    cout << endl;

    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += buffer[i];
    }

    cout << "Server calculated sum: " << sum << endl;

    write(write_to_client, &sum, sizeof(sum));

    close(read_from_client);
    close(write_to_client);
}

int main() {
    int pipe_client_to_server[2];
    int pipe_server_to_client[2];

    if (pipe(pipe_client_to_server) == -1 || pipe(pipe_server_to_client) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    int pid = fork();
    if (pid == 0) {  
        close(pipe_client_to_server[0]);
        close(pipe_server_to_client[1]);
        client(pipe_client_to_server[1], pipe_server_to_client[0]);
        exit(0);
    }

    pid = fork();
    if (pid == 0) {
        close(pipe_client_to_server[1]);
        close(pipe_server_to_client[0]);
        server(pipe_client_to_server[0], pipe_server_to_client[1]);
        exit(0);
    }

    wait(nullptr);
    wait(nullptr);

    return 0;
}
