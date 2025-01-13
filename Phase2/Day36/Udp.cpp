#include <iostream>
#include <unistd.h>
#include <cstring>
#include <string>
#include <sstream>
#include <cstdlib>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void server(int port);
void serveClient(int server_socket_fd, sockaddr_in& client_address, socklen_t& client_len);
void client(std::string server_ip, int port);
void requestServer(int client_socket_fd, sockaddr_in& server_address);

void server(int port) {
    int server_socket_fd;

    // Create socket
    if ((server_socket_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    sockaddr_in server_address, client_address;
    memset(&server_address, 0, sizeof(server_address));
    memset(&client_address, 0, sizeof(client_address));

    // Bind socket to port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    if (bind(server_socket_fd, (sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        close(server_socket_fd);
        exit(EXIT_FAILURE);
    }

    socklen_t client_len = sizeof(client_address);
    std::cout << "Server listening on port " << port << "...\n";

    while (true) {
        serveClient(server_socket_fd, client_address, client_len);
    }

    close(server_socket_fd);
}

void serveClient(int server_socket_fd, sockaddr_in& client_address, socklen_t& client_len) {
    char buffer[BUFFER_SIZE];
    long first, second;

    // Receive first number
    recvfrom(server_socket_fd, buffer, BUFFER_SIZE, 0, (sockaddr*)&client_address, &client_len);
    first = atol(buffer);

    // Receive second number
    recvfrom(server_socket_fd, buffer, BUFFER_SIZE, 0, (sockaddr*)&client_address, &client_len);
    second = atol(buffer);

    // Process numbers
    long sum = first + second;
    std::cout << "Processed: " << first << " + " << second << " = " << sum << "\n";

    // Send response
    std::string sumStr = std::to_string(sum);
    strcpy(buffer, sumStr.c_str());
    sendto(server_socket_fd, buffer, BUFFER_SIZE, 0, (sockaddr*)&client_address, client_len);
    std::cout << "\tResponse sent to client\n";
}

void client(std::string server_ip, int port) {
    int client_socket_fd;kn

    // Create socket
    if ((client_socket_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);

    if (inet_pton(AF_INET, server_ip.c_str(), &server_address.sin_addr) <= 0) {
        perror("Invalid address or address not supported");
        exit(EXIT_FAILURE);
    }

    // Request the server
    requestServer(client_socket_fd, server_address);

    close(client_socket_fd);
}

void requestServer(int client_socket_fd, sockaddr_in& server_address) {
    char buffer[BUFFER_SIZE];
    long first, second;

    std::cout << "First Number: ";
    std::cin >> first;
    std::cout << "Second Number: ";
    std::cin >> second;

    // Send numbers
    std::string firstStr = std::to_string(first);
    std::string secondStr = std::to_string(second);

    strcpy(buffer, firstStr.c_str());
    sendto(client_socket_fd, buffer, BUFFER_SIZE, 0, (sockaddr*)&server_address, sizeof(server_address));

    strcpy(buffer, secondStr.c_str());
    sendto(client_socket_fd, buffer, BUFFER_SIZE, 0, (sockaddr*)&server_address, sizeof(server_address));

    // Receive response
    recvfrom(client_socket_fd, buffer, BUFFER_SIZE, 0, nullptr, nullptr);

    long sum = atol(buffer);
    std::cout << "So, " << first << " + " << second << " = " << sum << "\n";
    std::cout << "I am thankful to my sum calculator server!!!\n";
}

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        std::cout << "usage:\n\t./sumCalculatorApp.out server 8080\n";
        std::cout << "\t./sumCalculatorApp.out client 127.0.0.1 8080\n";
        return EXIT_FAILURE;
    }

    if (!(
           (strcmp(argv[1], "client") == 0 && argc == 4) ||
           (strcmp(argv[1], "server") == 0 && argc == 3)
       )) {
        std::cout << "usage:\n\t./sumCalculatorApp.out server 8080\n";
        std::cout << "\t./sumCalculatorApp.out client 127.0.0.1 8080\n";
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "client") == 0) {
        std::cout << "Client [to server `" << argv[2] << ":" << argv[3] << "`]\n";
        client(argv[2], atoi(argv[3]));
    }
    if (strcmp(argv[1], "server") == 0) {
        std::cout << "Server [port:`" << argv[2] << "`]\n";
        server(atoi(argv[2]));
    }

    return EXIT_SUCCESS;
}
