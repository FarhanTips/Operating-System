
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide some integers.\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        int number = atoi(argv[i]);
        if (number % 2 == 0) {
            printf("%d is even.\n", number);
        } else {
            printf("%d is odd.\n", number);
        }
    }

    return 0;
}

