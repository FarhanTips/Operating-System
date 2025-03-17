

#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

struct shared {
    char sel[100];
    int b;
};

int main() {
    int sm_id;
    int fd[2]; 
    pid_t opr;
    struct shared *s_m;

    sm_id = shmget(IPC_PRIVATE, sizeof(struct shared), 0666 |IPC_CREAT );

    s_m = (struct shared *)shmat(sm_id, NULL, 0);
    (*s_m).b = 1000;
    int p = pipe(fd);
    if (p < 0) {
        perror("pipe error");
    }

    printf("Provide Your Input From Given Options:\n1. Type a to Add Money\n2. Type w to Withdraw Money\n3. Type c to Check Balance\n");

    scanf("%s", (*s_m).sel);
    printf("Your selection: %s\n", (*s_m).sel);

    opr = fork();
    if (opr == 0) {
        int amount;
        close(fd[0]);
        
        if ((*s_m).sel[0] == 'a') {
            printf("\n\nEnter amount to be added:\n");
            scanf("%d", &amount);
            if (amount > 0) {
                (*s_m).b += amount;
                printf("\nBalance added successfully\n\nUpdated balance after addition: %d\n\n", (*s_m).b);

            } else {
                printf("\nAdding failed, Invalid amount\n\n");
            }
        } 
        else if ((*s_m).sel[0] == 'w') {
            printf("\nEnter amount to be withdrawn:\n");
            scanf("%d", &amount);
            if (amount > 0 && amount <= (*s_m).b) {
                (*s_m).b -= amount;
                printf("\nWithdrawal successful\n\nUpdated balance after withdrawal: %d\n\n", (*s_m).b);
            } 
            else {
                printf("\nWithdrawal failed, Invalid amount\n\n");
            }

        } 
        else if ((*s_m).sel[0] == 'c') {
            printf("\nCurrent balance: %d\n\n", (*s_m).b);
        } 
        else {
            printf("\nInvalid selection\n\n");
        }

        char buff[200] = "Thank you for using";
        write(fd[1], buff, sizeof(buff));
        close(fd[1]);

        shmdt(s_m);

    } 
    else {
        wait(NULL);
        close(fd[1]);
        char read_buff[200];
        read(fd[0], read_buff, sizeof(read_buff));

        printf("%s\n", read_buff);
        //printf("Updated balance after withdrawal parrent: %d\n", (*s_m).b);

        close(fd[0]);
        shmdt(s_m);
        shmctl(sm_id, IPC_RMID, NULL);
    }

    return 0;
}