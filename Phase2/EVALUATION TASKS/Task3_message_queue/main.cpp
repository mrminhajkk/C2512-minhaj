#include <iostream>
#include <vector>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <cstring>
#include <string>
#include <unistd.h>

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

struct Message {
    long msg_type;
    int data[100];
};

void client(int msgid) {
    vector<Vaccination> vacc = {
        Vaccination("P001", 4), 
        Vaccination("P002", 5), 
        Vaccination("P003", 6), 
        Vaccination("P004", 15), 
        Vaccination("P005", 1)
    };

    int size = vacc.size();
    Message msg;
    msg.msg_type = 1;

    for (int i = 0; i < size; ++i) {
        msg.data[i] = vacc[i].getDoseAdministered();
    }

    cout << "Client sending doses: ";
    for (int i = 0; i < size; ++i) {
        cout << msg.data[i] << " ";
    }
    cout << endl;

    msgsnd(msgid, &msg, sizeof(msg.data), 0);

    int sum;
    msgrcv(msgid, &msg, sizeof(msg.data), 2, 0);
    sum = msg.data[0];
    cout << "Client received sum from server: " << sum << endl;
}

void server(int msgid) {
    Message msg;
    int sum = 0;

    msgrcv(msgid, &msg, sizeof(msg.data), 1, 0);

    cout << "Server received doses: ";
    for (int i = 0; i < 5; ++i) {
        cout << msg.data[i] << " ";
        sum += msg.data[i];
    }
    cout << endl;

    cout << "Server calculated sum: " << sum << endl;

    msg.msg_type = 2;
    msg.data[0] = sum;
    msgsnd(msgid, &msg, sizeof(msg.data), 0);
}

int main() {
    int msgid = msgget(IPC_PRIVATE, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("Message queue creation failed");
        return 1;
    }
    {
        int pid = fork();
        if (pid == 0) {
            client(msgid);
            return 0;
        }
    }
    
    {
        int pid = fork();
        if (pid == 0) {
            server(msgid);
            return 0;
        }
    }
    wait(nullptr);
    wait(nullptr);

    msgctl(msgid, IPC_RMID, nullptr);
    return 0;
}
