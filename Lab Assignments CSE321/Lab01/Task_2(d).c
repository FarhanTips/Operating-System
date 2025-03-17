#include <stdio.h>
#include <string.h>


int main() {
    char line[100];
    int j=0;
    printf("Enter a line: ");
    scanf("%[^\n]", line);
    for (int i=0; line[i] != '\0'; i++) {
        if (line[i] == '@') {
            if (line[i+1] == 's' && line[i+2] == 'h' && line[i+3] == 'e' && line[i+4] == 'b' && line[i+5] == 'a' && line[i+6] == '.' && line[i+7] == 'x' && line[i+8] == 'y' && line[i+9] == 'z' && line[i+10] == '\0') {
                printf("Email address is okay");
                return 0;
            }
            
            
        }
        
    }
    printf("Email address is outdated");

    return 0;
}