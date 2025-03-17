#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>


int main()
{
    pid_t pid, status;
    pid = fork();

    int array[8] = {24,44,1,34,56,78,33,11};
    if (pid == 0)
    {
        execv("/home/ub71103/Documents/sort.c", 8, array);
    }
    else if (pid > 0)
    {
        wait(&status);
        execv("/home/ub71103/Documents/oddeven.c.c", 8, array);
    }
    return 0;
}



