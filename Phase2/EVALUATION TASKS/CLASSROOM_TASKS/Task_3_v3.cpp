#include <iostream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>
#include <string>
#include <functional>

using namespace std;

namespace biz_type {
    using vector_size_t = int;
    using element_size_t = short; 
}

char buffer[1024];

class Vaccination {
private:
    string VaccinationId;
    biz_type::element_size_t DoseAdministered;
public:
    Vaccination(string id, biz_type::element_size_t dose) : VaccinationId(id), DoseAdministered(dose) {}

    biz_type::element_size_t getDoseAdministered() const { return DoseAdministered; }
};

template<class T, class SIZE_T, class FIELD_T>
void Serialize(vector<T> container, char* data_buffer, int buffer_size, function<FIELD_T(T)> getField) {
       /*biz_type::vector_size_t numOfVaccinations = vaccinations.size();
    char* ptr_buffer = buffer;
    memcpy(ptr_buffer, &numOfVaccinations, sizeof(biz_type::vector_size_t));
    ptr_buffer += sizeof(biz_type::vector_size_t);

    for (const auto& vac : vaccinations) {
        biz_type::element_size_t dose = vac.getDoseAdministered();
        memcpy(ptr_buffer, &dose, sizeof(biz_type::element_size_t));
        ptr_buffer += sizeof(biz_type::element_size_t);
    }*/
    //copy vector to container 
    SIZE_T size = container.size();
    
    memcpy(data_buffer, &size, sizeof(SIZE_T));
    data_buffer += sizeof(SIZE_T);

    for (const auto& e : container) {
        FIELD_T field = getField(e);
        memcpy(data_buffer, &field, sizeof(FIELD_T));
        data_buffer += sizeof(FIELD_T);
    }
}

template<class SIZE_T, class FIELD_T>
void DeSerialize(FIELD_T* arr, SIZE_T& size, char* data_buffer, int buffer_size) {
       /*char* ptr_buffer = buffer;
    biz_type::vector_size_t numOfVaccinations;
    memcpy(&numOfVaccinations, ptr_buffer, sizeof(biz_type::vector_size_t));
    ptr_buffer += sizeof(biz_type::vector_size_t);

    biz_type::element_size_t allDosages[numOfVaccinations];
    for (int i = 0; i < numOfVaccinations; ++i) {
        memcpy(&allDosages[i], ptr_buffer, sizeof(biz_type::element_size_t));
        ptr_buffer += sizeof(biz_type::element_size_t);
    }*/
    memcpy(&size, data_buffer, sizeof(SIZE_T));
    data_buffer += sizeof(SIZE_T);

    for (int i = 0; i < size; ++i) {
        memcpy(&arr[i], data_buffer, sizeof(FIELD_T));
        data_buffer += sizeof(FIELD_T);
    }
}


void client(int write_to_server, int read_from_server) {
    vector<Vaccination> vaccinations = {
        Vaccination("P001", 4), 
        Vaccination("P002", 5), 
        Vaccination("P003", 6), 
        Vaccination("P004", 15), 
        Vaccination("P005", 1)
    };

 
    Serialize<Vaccination, biz_type::vector_size_t, biz_type::element_size_t>(
        vaccinations,
        buffer,
        sizeof(buffer),
        [] (Vaccination vaccinatiion) -> biz_type::element_size_t {
            return vaccinatiion.getDoseAdministered();
        }
    );

    write(write_to_server, buffer, sizeof(buffer));

    biz_type::element_size_t sum;
    cout << "Client Send Vaccination Doses: ";
    for (const auto& vac : vaccinations) {
        cout << vac.getDoseAdministered() << " ";
    }
    cout << endl;
    read(read_from_server, &sum, sizeof(sum));
    cout << "Client received sum from server: " << sum << endl;

  
    

    close(write_to_server);
    close(read_from_server);
}

void server(int read_from_client, int write_to_client) {
    char buffer[1024];
    read(read_from_client, buffer, sizeof(buffer));
    biz_type::vector_size_t numOfVaccinations;
    biz_type::element_size_t allDosages[1000];
 
    DeSerialize<biz_type::vector_size_t, biz_type::element_size_t>(
        allDosages,
        numOfVaccinations,
        buffer,
        sizeof(buffer)
    );

    biz_type::element_size_t sum = 0;
    for (int i = 0; i < numOfVaccinations; ++i) {
        sum += allDosages[i];
    }
    cout << "Server Recieved Vaccination Doses: ";
    for (int i = 0; i < numOfVaccinations; ++i) {
        cout << allDosages[i] << " ";
    }
    cout << endl;
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

    { 
        int pid = fork();
        if (pid == 0) {  
            close(pipe_client_to_server[0]);
            close(pipe_server_to_client[1]);
            client(pipe_client_to_server[1], pipe_server_to_client[0]);
            exit(0);
        }
    }

    { 
        int pid = fork();
        if (pid == 0) {
            close(pipe_client_to_server[1]);
            close(pipe_server_to_client[0]);
            server(pipe_client_to_server[0], pipe_server_to_client[1]);
            exit(0);
        }
    }

    wait(nullptr);

    return 0;
}
