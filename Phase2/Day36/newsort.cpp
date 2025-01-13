#include <iostream>
#include <unistd.h>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define MAX_CONNS 5

void server(int port);
void serveClient(int&);
void client(std::string server_ip, int port);
void requestServer(int&);
void bubbleSort(std::vector<double>&);

void server(int port) {
    int server_socket_fd;
    // Create socket
    if ((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    sockaddr_in address;

    // Bind socket to port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (bind(server_socket_fd, (sockaddr*)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_socket_fd);
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_socket_fd, MAX_CONNS) < 0) {
        perror("Listen failed");
        close(server_socket_fd);
        exit(EXIT_FAILURE);
    }

    // Accept a connection
    int client_socket_fd;
    int addrlen = sizeof(address);
    if ((client_socket_fd = accept(server_socket_fd, (sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
        perror("Accept failed");
        close(server_socket_fd);
        exit(EXIT_FAILURE);
    }

    // Serve the client
    serveClient(client_socket_fd);

    // Close server socket
    close(server_socket_fd);
}

void serveClient(int& client_socket_fd) {
    char buffer[BUFFER_SIZE];
    int size;

    // Receive the size of the array
    read(client_socket_fd, buffer, sizeof(int));
    memcpy(&size, buffer, sizeof(int));

    // Receive the array
    std::vector<double> arr(size);
    read(client_socket_fd, buffer, size * sizeof(double));
    memcpy(arr.data(), buffer, size * sizeof(double));

    // Sort the array
    bubbleSort(arr);

    // Send the sorted array back
    memcpy(buffer, arr.data(), size * sizeof(double));
    write(client_socket_fd, buffer, size * sizeof(double));

    std::cout << "Sorted array: ";
    for (const auto& num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\nSorted array sent to client." << std::endl;

    // Close client socket
    close(client_socket_fd);
}

void client(std::string server_ip, int port) {
    int client_socket_fd = 0;
    // Create socket
    if ((client_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Specify server address
    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    if (inet_pton(AF_INET, server_ip.c_str(), &server_address.sin_addr) <= 0) {
        perror("Invalid address or address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(client_socket_fd, (sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Request the server
    requestServer(client_socket_fd);

    // Close client socket
    close(client_socket_fd);
}

void requestServer(int& client_socket_fd) {
    char buffer[BUFFER_SIZE];

    // Input the array
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    std::vector<double> arr(size);
    for (int i = 0; i < size; ++i) {
        std::cout << "Enter element " << i + 1 << ": ";
        std::cin >> arr[i];
    }

    // Send the size of the array
    memcpy(buffer, &size, sizeof(int));
    write(client_socket_fd, buffer, sizeof(int));

    // Send the array
    memcpy(buffer, arr.data(), size * sizeof(double));
    write(client_socket_fd, buffer, size * sizeof(double));

    // Receive the sorted array
    read(client_socket_fd, buffer, size * sizeof(double));
    memcpy(arr.data(), buffer, size * sizeof(double));

    // Print the sorted array
    std::cout << "Sorted array received from server: ";
    for (const auto& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void bubbleSort(std::vector<double>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        std::cout << "usage:\n\t./sortServerApp.out server 8080" << std::endl;
        std::cout << "\t./sortServerApp.out client 127.0.0.1 8080" << std::endl;
        return EXIT_FAILURE;
    }

    if (!(
        (strcmp(argv[1], "client") == 0 && argc == 4) ||
        (strcmp(argv[1], "server") == 0 && argc == 3)
    )) {
        std::cout << "usage:\n\t./sortServerApp.out server 8080" << std::endl;
        std::cout << "\t./sortServerApp.out client 127.0.0.1 8080" << std::endl;
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "client") == 0) {
        std::cout << "Client [to server `" << argv[2] << ":" << argv[3] << "`]" << std::endl;
        client(argv[2], atoi(argv[3]));
    }
    if (strcmp(argv[1], "server") == 0) {
        std::cout << "Server [port:`" << argv[2] << "`]" << std::endl;
        server(atoi(argv[2]));
    }

    return EXIT_SUCCESS;
}
