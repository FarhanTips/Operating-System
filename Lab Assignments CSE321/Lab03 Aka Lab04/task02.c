
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>


struct msg {
    long int type;
    char txt[6];
};

int main() {
    int msg_id = msgget((key_t)12,0666|IPC_CREAT);
    if (msg_id == -1) {
        perror("Error!");
        exit(1);
    }

    printf("Please enter the workspace name:\n");
    char name_workspace[20];
    scanf("%s", name_workspace);

    if (strcmp(name_workspace, "cse321") != 0) {
        printf("Invalid workspace name\n");
        exit(1);
    }

    struct msg login_msg;
    login_msg.type = 1; 
    strcpy(login_msg.txt, name_workspace);
    
    int snt = msgsnd(msg_id, &login_msg, sizeof(login_msg.txt),0);
    if (snt == -1) {
        perror("Error! sending from log_in to otp_msg\n");
        exit(1);
    }
    printf("Workspace name sent to otp generator from log in: %s\n\n\n", login_msg.txt);

    pid_t otp = fork();
    if (otp == -1) {
        perror("Error! fork");
        exit(1);
    }
    if (otp == 0) {  // log_in child or otp process
        pid_t mail = fork();
        if (mail>0) {
            struct msg otp_msg;
            
            if (msgrcv(msg_id, &otp_msg, sizeof(otp_msg.txt), 1, 0) == -1) {
                perror("Error! receiving otp_msg from log_in\n");
                exit(1);
            }
            printf("OTP generator received workspace name from log in: %s\n\n\n", otp_msg.txt);

            int otp = getpid();
            sprintf(otp_msg.txt, "%d", otp);

            otp_msg.type = 2; 
            if (msgsnd(msg_id, &otp_msg, sizeof(otp_msg.txt), 0) == -1) {
                perror("Error! sending from otp to log_in\n");
                exit(1);
            }
            printf("OTP sent to log in from OTP generator: %s\n", otp_msg.txt);

            otp_msg.type = 3; 
            if (msgsnd(msg_id, &otp_msg, sizeof(otp_msg.txt), 0) == -1) {
                perror("Error! sending from otp mail\n");
                exit(1);
            }
            printf("OTP sent to mail from OTP generator: %s\n", otp_msg.txt);

            exit(0);
        }
    

        else if (mail == 0) {   // otp child or mail process
            //wait(NULL);
            struct msg mail_msg;
            
            if (msgrcv(msg_id, &mail_msg, sizeof(mail_msg.txt), 3, 0) == -1) {
               perror("Error! mail is receiving from otp\n");
                exit(1);
            }
            printf("Mail received OTP from OTP generator: %s\n", mail_msg.txt);
            
            mail_msg.type = 4;
            if (msgsnd(msg_id, &mail_msg, sizeof(mail_msg.txt), 0) == -1) {
                perror("Error! sending from mail to log_in");
                exit(1);
            }
            printf("OTP sent to log in from mail: %s\n", mail_msg.txt);

            exit(0);
        }
    }
    else {   // log_in parrent or log_in process
        wait(NULL);

        struct msg login_mail_msg;
        struct msg login_otp_msg;
        
        if (msgrcv(msg_id, &login_otp_msg, sizeof(login_otp_msg.txt), 2, 0) == -1) {
            perror("Error! log_in receiving from otp\n");
            exit(1);
        }
        printf("Log in received OTP from OTP generator: %s\n", login_otp_msg.txt);
        
        if (msgrcv(msg_id, &login_mail_msg, sizeof(login_mail_msg.txt), 4, 0) == -1) {
            perror("Error! log_in receiving from mail\n");
            exit(1);
        }
        printf("Log in received OTP from mail: %s\n", login_mail_msg.txt);


        if (strcmp(login_otp_msg.txt, login_mail_msg.txt) == 0) {
            printf("OTP Verified\n");
        } 
        else {
            printf("OTP Incorrect\n");
        }
        
        
        msgctl(msg_id,IPC_RMID,0);
    }

    return 0;
}