
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pid, status,g;
    pid = fork();
    if (pid == -1)
    {
        perror("fork failed");
        exit(1);
    }
    if (pid == 0)
    {
        printf("Child Process: PID = %d\n", getpid());       
        //printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        for (int i = 1; i <= 3; i++) {
            g = fork();
            if (g == -1) {
                perror("fork failed");
                exit(1);
            }
            if (g == 0) {
                printf("Grandchild %d: PID = %d\n", i, getpid());
                //printf("Grandchild %d: PID = %d, Parent PID = %d\n", i, getpid(), getppid());
                exit(0);
            }
        }
    }
    else
    {
        printf("Parent Process: PID = %d\n", getpid());
        wait(&status);
    }
    return 0;
}