
#include <stdio.h>
#include <stdlib.h>

#define max_Length 100

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Invalid arguments!");
        return 1;
    }

    FILE *new_file = fopen(argv[1], "a");
    if (new_file == NULL) {
        perror("Error");
        return 1;
    }

    char input[max_Length];

    while (1) {
            printf("Enter string (type '-1' to stop): ");
        fgets(input, max_Length, stdin);

        if (input[0] == '-' && input[1] == '1' && input[2] == '\0') {
            break;
        }
        fprintf(new_file, "%s", input);
    }

    fclose(new_file);

    return 0;
}