#include <stdio.h>
void Rotate_Matrix(int n, int matrix[n][n]){
    for(int i=0; i<n ; i++){
        for(int j=i; j<n; j++){
            int temp=matrix[i][j];
            matrix[i][j]=matrix[j][i];
            matrix[j][i]=temp;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n/2; j++){
            int temp=matrix[i][j];
            matrix[i][j]=matrix[i][n-j-1];
            matrix[i][n-j-1]=temp;
        }
    }
}
void PrintMatrix(int n, int matrix[n][n]){ //Function for printing matrix
    for(int i=0; i<n; i++){
        for(int j=0; j<n;j++){
            printf("%d",matrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int n;
    printf("Enter size of matrix : \n");
    scanf("%d",&n);

    int matrix[n][n];
    printf("Enter elements of %dx%d matrix \n",n,n); //taking inputs for nxn matrix
    for(int i=0; i<n; i++){
        for(int j=0; j<n;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    printf("\n The Original Matrix \n");
    PrintMatrix(n,matrix);

    Rotate_Matrix(n,matrix);

    printf("\nMatrix after 90 degree Rotation : \n");
    PrintMatrix(n,matrix);
    return 0;

}