#include <iostream>
#include <vector>
#include <climits>
#include <unistd.h>

using namespace std;

class Vaccination {
    private:
        string VaccinationId;
        int DoseAdministered;
    public:
        Vaccination(string id, int dose) : VaccinationId(id), DoseAdministered(dose) {}

        string getVaccinationId() const {
            return VaccinationId;
        }

        int getDoseAdministered()  {
            return DoseAdministered;
        }
};


//     int findsum(const vector<Vaccination>& vacc) {
//     int sum = 0;
//     for (const auto& each : vacc) {
//         sum += each.getDoseAdministered();
//     }
//     return sum;
// }

// void find_min_in_firsthalf(const vector<Vaccination>& vacc, int& min) {
//     min = INT_MAX;
//     for (int i = 0; i < vacc.size() / 2; ++i) {
//         if (vacc[i].getDoseAdministered() < min) {
//             min = vacc[i].getDoseAdministered();
//         }
//     }
// }

// void find_max_in_secondhalf(const vector<Vaccination>& vacc, int& max) {
//     max = INT_MIN;
//     for (int i = vacc.size() / 2; i < vacc.size(); ++i) {
//         if (vacc[i].getDoseAdministered() > max) {
//             max = vacc[i].getDoseAdministered();
//         }
//     }
// }

void client(int& read_client, int& write_to_server){
    int arr[100];
    int buffer[100];
    vector<Vaccination> vacc = { Vaccination("P001", 4), Vaccination("P002", 5), Vaccination("P003", 6), Vaccination("P004", 15), Vaccination("P005", 1) };
    
        for (int i = 0; i < vacc.size(); ++i) {
      arr[i]=vacc[i].getDoseAdministered();
        }
        for(int i=0;i<5;i++){
    write(write_to_server,(void*)&arr[i],sizeof(arr));
    close(write_to_server);
        }
    }
        read(read_client,(void*)&buffer,sizeof(buffer));
        cout << *buffer ;


void server(int& read_server, int& write_to_client){
    int buffer[100];
    int a;
    read(read_server,(void*)&buffer,sizeof(buffer));
    
    //  for(int i=0;i<5;i++)
    //     {
    //         sum = sum + arr[i];
    //     }
    //     close(rea
    int sum=0;
    
        for(int i=0;i<sizeof(buffer);i++)
        {
            sum = sum + buffer[i];
        }
        close(read_server);
        write(write_to_client,(void*)&sum,sizeof(int));
        



}
int main() {

    int pipe_fd1[2];
    if(pipe(pipe_fd1)==-1){
        perror("Pipe");
        cout << "Pipe not created" << endl ;
    }

    int &read_server = pipe_fd1[0];
    int &write_to_client = pipe_fd1[1];

        int pipe_fd2[2];
    if(pipe(pipe_fd2)==-1){
        perror("Pipe");
        cout << "Pipe not created" << endl ;
    }

    int &read_client = pipe_fd2[0];
    int &write_to_server = pipe_fd2[1];

    int pid = -1;

    {
        pid = fork();
        if(0 == pid){
            client(read_client,write_to_server);
        }
    }


    {
        pid = fork();
        if(0==pid){
            server(read_server,write_to_client);
        }
    }
    // vector<Vaccination> vacc = { Vaccination("P001", 11), Vaccination("P002", 5), Vaccination("P003", 6), Vaccination("P004", 15), Vaccination("P005", 1) };
    
    // int sum = findsum(vacc);
    // cout << "The sum is " << sum << endl;

    // int min;
    // find_min_in_firsthalf(vacc, min);
    // cout << "The min in first half is " << min << endl;

    // int max;
    // find_max_in_secondhalf(vacc, max);
    // cout << "The max in second half is " << max << endl;

    return 0;
}
