#include <stdio.h>
#include <string.h>

int main() {
    char line[100];
    int j = 0;
    char new_line[100];
    FILE *file;

    file = fopen("spaceed.txt", "r");
    if (file == NULL) {
        printf("File is Blank.\n");
        return 0;
    }

    if (fgets(line, sizeof(line), file) != NULL) {
        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] != ' ') {
                new_line[j] = line[i];
                j++;
            } 
            else {
                if (line[i+1] != ' ') {
                    new_line[j] = line[i];
                    j++;
                }
            }
        }
        new_line[j] = '\0';
        
    } 
    else {
        printf("Error. Cannot Open the file to read.\n");
        fclose(file);
        return 0;
    }

    fclose(file);

    file = fopen("spaced.txt", "w");
    if (file == NULL) {
        printf("Error. Cannot Open the file to write.\n");
        return 0;
    }

    fprintf(file, "%s", new_line);

    fclose(file);

    return 0;
}