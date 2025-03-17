#include <stdio.h>
#include <string.h>
#include <stdbool.h>


void check_palindrome(char *new) {
    char *second;
    second=new;
    int len = strlen(new);
    //printf("%c\n",*new);
    second +=(len-1);
    //printf("%c\n",*second);
    for (new; new<second; new++, second--) {
        if (*new!=*second) {
            printf("Not Palindrome\n");
            return;
        }
    }
    printf("Palindrome\n");
    
}

int main() {
    char line[100];
    printf("Enter a line: ");
    scanf("%[^\n]", line);
    check_palindrome(line);

    return 0;
}