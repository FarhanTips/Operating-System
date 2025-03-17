

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int results[3]; 

void *sum_ascii(void *arg);

int main()
{
    pthread_t threads[3];
    char *names[3] = {"Farhan", "Akbor", "Khan"};


    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, sum_ascii, (void *)names[i]);
    }


    for (int i = 0; i < 3; i++) {
        int *output;
        pthread_join(threads[i], &output);
        results[i] = (int*) output; 
    }


    if (results[0] == results[1] && results[1] == results[2]) {
        printf("Youreka\n");
    }
    else if ( ( results[0] == results[1] ) || ( results[0] == results[2] ) || ( results[1] == results[2] ) ) {
        printf("Miracle\n");
    }
    else {
        printf("Hasta la vista\n");
    }

    return 0;
}



void *sum_ascii(void *arg) {
    char *name = (char *)arg;
    int i = 0, 
    sum = 0;
    while (name[i] != '\0') {
        sum += name[i];
        i++;
    }
    pthread_exit(sum); 
}