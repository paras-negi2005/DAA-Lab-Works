#include <stdio.h>
int main() {
    int arr[4]={10,20,58,40};
    int n=4;
    int c=0;
    for(int k=0;k<n;k++){
        printf("%d ",arr[k]);
    }
    for(int i=0;i<n-1;i++){
        int swap_count=0;
        for(int j=0;j<n-i-1;j++){
            if (arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swap_count=1;
                c++;
            }
        }
        if (swap_count==0){
            break;
        }
    }
    printf("\n");
    for(int k=0;k<n;k++){
        printf("%d ",arr[k]);
    }
    printf("\n");
    printf("COUNT :%d",c);
    return 0;
}
