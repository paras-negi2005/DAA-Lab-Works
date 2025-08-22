#include <stdio.h>

int gcd(int a,int b) {
    while(b!=0) {
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

int main() {
    int num1,num2,GCD,LCM;
    printf("Enter two numbers: ");
    scanf("%d %d",&num1,&num2);

    GCD=gcd(num1,num2);
    LCM=(num1*num2)/GCD;

    printf("GCD = %d\n",GCD);
    printf("LCM = %d\n",LCM);

    return 0;
}
