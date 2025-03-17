
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int compare_num(void *x, void *y);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide some integers.\n");
        return 1;
    }

    int number = argc - 1; 
    int *array = malloc(number * sizeof(int));  


    for (int i = 0; i < number; i++) {
        array[i] = atoi(argv[i + 1]);
    }

    qsort(array, number, sizeof(int), compare_num);

    printf("Descending Order: ");
    for (int i = 0; i < number; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}


int compare_num(void *x, void *y) {
    return (*(int*)y - *(int*)x);
}