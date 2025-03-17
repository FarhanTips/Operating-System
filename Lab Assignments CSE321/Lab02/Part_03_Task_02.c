
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread_function(void* arg);

int main() {
    pthread_t threads[5];
    int number[5];

    for (int i = 0; i < 5; i++) {
        number[i] = i;
        pthread_create(&threads[i], NULL, thread_function, &number[i]);
        pthread_join(threads[i], NULL);
    }
    return 0;
}


void* thread_function(void* arg) {
    int thread_number = * (int*) arg;
    
    for (int i = (thread_number *5 + 1); i < (thread_number *5 + 6); i++) {
        printf("Thread %d prints %d\n", thread_number, i);
        sleep(1);
    }
}

