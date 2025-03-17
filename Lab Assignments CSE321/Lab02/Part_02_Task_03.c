
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    pid_t a,b,c;
    int process_count=1;
    
    a=fork();
    b=fork();
    c=fork();

    if(a==0){
        if (getpid()%2!=0){
              fork();
        }
    }
    else{
        printf("PID of a: %d\n",a);
        if (a%2!=0) {
            process_count++;
        }
        process_count++;
    
    
        
        if(b==0){
            if (getpid()%2!=0){\
                fork();
            }
        }    
        else{
            printf("PID of b: %d\n",b);
            if (b%2!=0) {
                process_count++;
            }
            process_count++;


            if(c==0){
                if (getpid()%2!=0){
                    fork();
                }
            }
            else{
                printf("PID of c: %d\n",c);
                if (c%2!=0) {
                    process_count++;
                }
                process_count++;
                printf("Process created %d\n",process_count);
            }
        }
    
    }
    
    return 0;
}