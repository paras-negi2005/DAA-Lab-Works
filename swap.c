#include <stdio.h>
void Swap(int a, int b){
    int temp= a;
    a=b;
    b=temp;
    printf(" First number : %d , Second number : %d",a,b);
}
int main() {
    int num1,num2;
    printf("Enter First number : ");
    scanf("%d",&num1);
    printf("Enter Second number : ");
    scanf("%d",&num2);
    printf("...............Before swap...........\n");
    printf("First number : %d , Second number : %d \n",num1,num2);
    printf("...............After Swap............\n");
    Swap(num1,num2);
    return 0;
}