#include <iostream>
#include <vector>
#include <unistd.h>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define MAX_CONNS 5

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

void server(int port);
void serveClient(int& client_socket_fd);
void client(string server_ip, int port);
void sendVaccinationData(int& client_socket_fd);

void server(int port) {
    int server_socket_fd;
    
    if ((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (bind(server_socket_fd, (sockaddr*)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_socket_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket_fd, MAX_CONNS) < 0) {
        perror("Listen failed");
        close(server_socket_fd);
        exit(EXIT_FAILURE);
    }


    int client_socket_fd;
    int addrlen = sizeof(address);
    if ((client_socket_fd = accept(server_socket_fd, (sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
        perror("Accept failed");
        close(server_socket_fd);
        exit(EXIT_FAILURE);
    }

    serveClient(client_socket_fd);

   
    close(server_socket_fd);
}

void serveClient(int& client_socket_fd) {
    char buffer[BUFFER_SIZE];
    int size;

    
    read(client_socket_fd, buffer, sizeof(int));
    memcpy(&size, buffer, sizeof(int));


    vector<int> doses(size);
    read(client_socket_fd, buffer, size * sizeof(int));
    memcpy(doses.data(), buffer, size * sizeof(int));

  
    cout << "Server received array: ";
    for (int dose : doses) {
        cout << dose << " ";
    }
    cout << endl;

    
    int sum = 0;
    for (int dose : doses) {
        sum += dose;
    }

    
    memcpy(buffer, &sum, sizeof(int));
    write(client_socket_fd, buffer, sizeof(int));

    cout << "Server calculated sum: " << sum << endl;

   
    close(client_socket_fd);
}

void client(string server_ip, int port) {
    int client_socket_fd = 0;
    
    if ((client_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    if (inet_pton(AF_INET, server_ip.c_str(), &server_address.sin_addr) <= 0) {
        perror("Invalid address or address not supported");
        exit(EXIT_FAILURE);
    }

  
    if (connect(client_socket_fd, (sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

  
    sendVaccinationData(client_socket_fd);

   
    close(client_socket_fd);
}

void sendVaccinationData(int& client_socket_fd) {
    char buffer[BUFFER_SIZE];

    
    vector<Vaccination> vacc = {
        Vaccination("P001", 4),
        Vaccination("P002", 5),
        Vaccination("P003", 6),
        Vaccination("P004", 15),
        Vaccination("P005", 1)
    };

    int size = vacc.size();
    vector<int> doses(size);
    for (int i = 0; i < size; ++i) {
        doses[i] = vacc[i].getDoseAdministered();
    }

   
    cout << "Client sending array: ";
    for (int dose : doses) {
        cout << dose << " ";
    }
    cout << endl;

    
    memcpy(buffer, &size, sizeof(int));
    write(client_socket_fd, buffer, sizeof(int));

    
    memcpy(buffer, doses.data(), size * sizeof(int));
    write(client_socket_fd, buffer, size * sizeof(int));

    
    int sum;
    read(client_socket_fd, buffer, sizeof(int));
    memcpy(&sum, buffer, sizeof(int));

    cout << "Client received sum from server: " << sum << endl;
}

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        cout << "usage:\n\t./vaccinationApp server 8080" << endl;
        cout << "\t./vaccinationApp client 127.0.0.1 8080" << endl;
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "server") == 0) {
        if (argc != 3) {
            cout << "usage:\n\t./vaccinationApp server <port>" << endl;
            return EXIT_FAILURE;
        }
  
        cout << "Server listening on port " << argv[2] << endl;
        server(atoi(argv[2]));
    }

    if (strcmp(argv[1], "client") == 0) {
        if (argc != 4) {
            cout << "usage:\n\t./vaccinationApp client <server_ip> <port>" << endl;
            return EXIT_FAILURE;
        }
        cout << "Client connecting to server at " << argv[2] << ":" << argv[3] << endl;
        client(argv[2], atoi(argv[3]));
    }

    return EXIT_SUCCESS;
}
