

#include <stdio.h>

int check_perfect(int num) {
    int sum = 0;
    for (int j=1; j<num; j++) {
        if (num%j==0) {
            sum += j;
        }
    }
    if (sum==num) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    int s_val, e_val;
    printf("Enter starting value: ");
    scanf("%d", &s_val);
    printf("Enter ending value: ");
    scanf("%d", &e_val);
    
    for (int i=s_val; i<=e_val; i++) {
        if (check_perfect(i)) {
            printf("%d\n",i);
        }
    }
    return 0;
}