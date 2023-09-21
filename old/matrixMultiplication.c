#include<stdio.h>
int main(){
    int A[3][3]={{1,2,3},
                 {4,6,6},
                 {7,8,9}};
    int B[3][3]={{1,2,3},
                 {4,5,5},
                 {7,8,9}};
    int C[3][3]={{0,0,0},
                 {0,0,0},
                 {0,0,0}};
    // sum of A_row x B_row
    for(int k = 0;k<3;k++){
        for(int j = 0;j<3;j++){
            for (int i = 0; i < 3; i++){
                C[k][j]+=A[k][i]*B[i][j];
            }
        }
    }
    for(int k = 0;k<3;k++){
        for(int j = 0;j<3;j++){
            printf("%d ", C[k][j]);
        }
        printf("\n");
    }
    
    

return 0;
}