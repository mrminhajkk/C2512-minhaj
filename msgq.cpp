//two processing - concurrent programming
//IPC (inter process communication) via pipe
#include<iostream>
#include<unistd.h>
#include<cstring>
#include <sys/msg.h>
#include <sys/wait.h>

#define MSG_KEY 234

struct msgb {
    long mtype;
    char mtext[1025];
};



void client(int& msgid) { //client
    msgb message;
   if(msgrcv(msgid , &message, sizeof(message.mtext), 0, 0) == -1){
    perror("Message recieve error");
    exit(1);
   }
   std::cout << "Message recieved : " << message.mtext << std::endl;
}

void server(int& msgid) { //server
    msgb message;
    message.mtype = 23;
    strcpy(message.mtext, "Bye Bye");

    if(msgsnd(msgid, &message ,sizeof(message.mtext),0) == -1){
        perror("Message Failed!!");
        exit(1);
    }
    std::cout << "Message sent succesfully." << std::endl;
}

int main() {
    int msgid = msgget(MSG_KEY, 0666 | IPC_CREAT);
   
    pid_t pid = -1;

    {   //child 1
        pid = fork();
        if(0 == pid) {
            server(msgid);
            sleep(2);
            msgctl(msgid, IPC_RMID, nullptr);
            return 0;
        }
    }

    {   //child 2
        pid = fork();
        if(0 == pid) {
            client(msgid);
            return 0;
        }
    }

    // no parent process
    wait(nullptr);
    return 0;
}
