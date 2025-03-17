
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid, status,pid2;
    pid = fork();
    if (pid == -1) {
        perror("fork failed");
        exit(1);
    }
    if (pid == 0) { 
        pid2=fork();
        if (pid2==-1) {
            perror("fork failed");
            exit(1);
        }
        if (pid2==0) {
            printf("I am grandchild\n");
        }
        else {
            wait(&status);
            printf("I am child\n");
        }
    }
    else { 
        wait(&status); 
        printf("I am parent\n");
    }
    return 0;
}
