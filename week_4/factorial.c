#include <stdio.h>
int Factorial(int num){
    if (num==0 || num==1){
        return 1;
    }
    else{
        return num * Factorial(num-1);
    }
}
int main() {
    int n;
    printf("Enter the number whose factorial you want : ");
    scanf("%d",&n);
    printf("Factorail of the number %d is %d",n,Factorial(n));
    return 0;
}