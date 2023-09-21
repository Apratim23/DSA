//sum of digits of 5 digit no.
#include <stdio.h>

int main() {
    int n;
    int sum=0;
    printf("Enter the 5 digit no.:");
    scanf("%d",&n);
    if(n>99999 || n<10000){
        printf("\nWrong no.");

    }
    else{
        while(n != 0){
        sum += n % 10;
        n = n/10;
    }
    printf("\nSum of digits is: %d",sum);
    }
    return 0;
}