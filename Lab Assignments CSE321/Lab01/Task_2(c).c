
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char line[100];
    printf("Enter a line: ");
    scanf("%[^\n]", line);
    bool capital = false;
    bool lower = false;
    bool special_character = false;
    bool digit = false;
    
    for (int i=0; line[i] != '\0'; i++) {
        if ('a' <= line[i] && line[i] <= 'z') {
            lower = true;
        }
        else if ('A' <= line[i] && line[i] <= 'Z') {
            capital = true;
        }
         else if ('1' <= line[i] && line[i] <= '9') {
            digit = true;
        } 
         else if (line[i] == '@' || line[i] == '#' || line[i] == '$' || line[i] <= '_') {
            special_character = true;
        }    
    }
    
    if (lower==false) {
        printf("Lowercase character missing\n");
    }
    if (capital==false) {
        printf("Uppercase character missing\n");
    }
    if (digit==false) {
        printf("Digit missing\n");
    }
    if (special_character==false) {
        printf("Special character missing\n");
    }
    if (lower==true && capital==true && digit ==true && special_character==true) {
        printf("OK\n");
    }

    return 0;
}