#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <string>



server(int& write_end){
    char* msg = "Hello";
    write(write_end, msg ,sizeof(msg));
    close(write_end);

}

client(int& read_end){
    char buffer[1024];
    read(read_end, buffer , sizeof(buffer));
    close(read_end);

}



int main() {
    int pipe_fd[2];
    if(pipe(pipe_fd==-1)){
        perror("pipe not crdeated");
        return 1;
    }
    int& read_end = pipe_fd[0];
    int& write_end = pipe_fd[1];

    {
        pid = fork();
        if(pid==0){
           close(read_end);
           server(write_end); 
           return 0;
        }
    }

    {
        pid = fork();
        if(pid==0){
            close(write_end);
            client(read_end);
            return 0;
        }
    }
    wait(nullptr);
    return 0;
}