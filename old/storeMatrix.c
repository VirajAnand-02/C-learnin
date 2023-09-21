#include<stdio.h>
int main(){
    int A[5][5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            printf("Enter number, i=%d, j=%d", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    printf("The matrix is : ");
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
return 0;
}