#include <stdio.h>
int main() {
    int num,newNum,remainder,n=0,result=0;
    printf("Enter an integer: ");
    scanf("%d",&num);
    newNum=num;
    while(newNum!=0) {
        newNum/=10;
        n++;
    }
    newNum=num;
    while(newNum!=0) {
        remainder=newNum%10;
        int power=1;
        for(int i=0;i<n;i++) {
            power*=remainder;
        }
        result+=power;
        newNum/=10;
    }
    if(result==num)
        printf("%d is an Armstrong number.\n",num);
    else
        printf("%d is not an Armstrong number.\n",num);
    return 0;
}
