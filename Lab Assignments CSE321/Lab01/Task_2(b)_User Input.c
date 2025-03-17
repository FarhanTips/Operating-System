
#include <stdio.h>
#include <string.h>


int main() {
    char line[100];
    int j=0;
    char new_line[100];
    printf("Enter a line: ");
    scanf("%[^\n]", line);
    for (int i=0; line[i] != '\0'; i++) {
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
    printf("%s",new_line);

    return 0;
}