#include <stdio.h>


int main() {
    int num1, num2, res;
    char op= ' '; // +, - and *
    printf("Enter two numbers: \n");
    scanf("%d %d", &num1,&num2);

    if (num1>num2){
        printf("Number 1: %d is greater. Subtraction between (%d - %d) : %d \n", num1, num1,num2,(num1-num2));
    }
    else if(num2>num1){
            printf("Number 2: %d is greater. Addition between (%d + %d) : %d \n", num2, num1,num2,(num1+num2));
    }
    else {
            printf("Number 1 and Number 2 is equal. Multiplication between (%d X %d): %d \n", num1,num2,(num1*num2));
    }

    return 0;
} 
