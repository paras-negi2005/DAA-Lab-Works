#include <stdio.h>
int Fibonacci(int num){
    if (num==0){
        return 0;
    }
    else if(num==1){
        return 1;
    }
    else{
        return Fibonacci(num-1)+Fibonacci(num-2);
    }
}
int main() {
    int n;
    printf("Enter the range to which you want fibonacci series : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("%d",Fibonacci(i));
        printf("\n");
    }
    return 0;
}