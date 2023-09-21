#include<stdio.h>
int prime[10];
int *arr=prime;
int chkPrime(int n){
    if(n <= 1){
        return 0;
    }
    for(int i=2;i<n/2+1;i++){
        if(n%i == 0){
            return 0;
        }
    }
    return 1;
}

void putN(int n, int i, int * add){
    *(add+i) = n;
}

int main(){
    for(int i=0,n=1;i<10;n++){
        if(chkPrime(n)){
            putN(n, i, arr);
            i++;
        }
    }
    for(int i =0;i<10; i++){
        printf("%d \n", *(arr+i));
    }
return 0;
}