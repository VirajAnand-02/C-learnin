#include<stdio.h>
#include<stdlib.h>
int size;

int aIJ(int *matrix, int i, int j){
    return *(matrix +(i-1+(size*(j-1))));
}

void putIJ(int *matrix, int i, int j, int val){
    *(matrix +(i-1+(size*(j-1)))) = val;
}

int main(){
    printf("enter size of matrix : ");
    scanf("%d", &size);
    int *A = (int *)malloc(size*size*sizeof(int));// Allocation
    int *B = (int *)malloc(size*size*sizeof(int));
    int C[size][size];// Output matrix

    for(int i=0;i<size;i++){// Printing result
        for(int j=0;j<size;j++){
            C[i][j]=0;
        }
    }

    for(int i=0;i<size;i++){ // set matrix | here for example Aij = ixj | i,j are zero indexed
        for(int j=0;j<size;j++){
            putIJ(A, i, j, i*j);
            putIJ(B, i, j, i*j);
        }
    }
    
    for(int k=0;k<size;k++){// Actual multiplication
        for(int j=0;j<size;j++){
            for (int i=0; i<size; i++){
                C[k][j]+=aIJ(A, k, i)*aIJ(B, i, j);
            }
        }
    }

    for(int k=0;k<size;k++){// Printing result
        for(int j=0;j<size;j++){
            printf("%d ", C[k][j]);
        }
        printf("\n");
    }

    free(A);
    free(B);
return 0;
}