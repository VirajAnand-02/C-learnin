#include<stdio.h>
#include<stdlib.h>

float ferh(float celcius){
    return celcius*(9.0f/5.0f) + 32;
}

int main(){
    float cel;
    printf("Enter temp in celcius: ");
    scanf("%f", &cel);
    printf("temp in farenheit is : %f", ferh(cel));
return 0;
}