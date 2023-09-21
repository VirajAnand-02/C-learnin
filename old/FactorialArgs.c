#include<stdio.h>
#include<stdlib.h>
long long int fact(long long int x){
    if(x < 0){
        printf("Error : factorial of -ve number.\n");
        exit(0);
    }
    else if(x == 1 || x == 0){
        return 1;
    }
    else if(x > 1){
        return (x*fact(x-1));
    }
}
int main(int argc, char *argv[]){
    long int number = atoi(argv[1]);
    if(argc == 1){
        printf("Missing arguments : Int Number \n");
        exit(0);
    }
    if(argc > 2){
        printf("Too many arguments : \n");
        exit(0);
    }
    else{
        printf("%lld \n", fact(number));
    }
    return 0;
}