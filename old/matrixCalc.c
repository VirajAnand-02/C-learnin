#include<stdio.h>
#define size 5
int A[5][5]={{1,2,3,4,5},
             {1,2,3,4,5},
             {1,2,3,4,5},
             {1,2,3,4,5},
             {1,2,3,4,5},};
int B[5][5]={{1,2,3,4,5},
             {1,2,3,4,5},
             {1,2,3,4,5},
             {1,2,3,4,5},
             {1,2,3,4,5},};
int c[5][5];

void getMatrix(int *X[0][0]){
    printf("Enter matrix :\n");
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            scanf("%d", X[i][j]);
        }
    }
}

int *add(int *a, int *b, int sign){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            c[i][j]=*(a+(i+size*j))+sign*(*(b+(i+size*j)));
        }
    }
    return &c[0][0];
}

int *mult(int *a, int *b){
    for(int k = 0;k<size;k++){
        for(int j = 0;j<size;j++){
            for (int i = 0; i < size; i++){
                c[k][j]+=A[k][i]*B[i][j];
            }
        }
    }
    return &c[0][0];
}
int main(){
    int input;
    int *resultPtr;
    printf("select option:\n\t1) Add\n\t2) Subtract\n\t3) Multiply\n\t)4 Inverse\n:  ");
    scanf("%d", &input);
    switch(input){
        case 1:
            printf("Addition : \n");
            resultPtr = add(&A[0][0], &B[0][0], 1);
            break;
        case 2:
            printf("Addition : \n");
            resultPtr = add(&A[0][0], &B[0][0], -1);
            break;
        case 3:
            printf("Multiplication : \n");
            resultPtr = mult(&A[0][0], &B[0][0]);
            break;
        case 4:
            break;
        default:
            printf("Invalid input \n");
            break;
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            printf("%d ", *(resultPtr+(i+size*j)));
        }
        printf("\n");
    }
return 0;
}