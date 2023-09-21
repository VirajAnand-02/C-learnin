#include<stdio.h>
#include <stdlib.h>
#include<time.h>
int main(){
    float block = 1;
    float slide = 0.5;
    float triger = 0.5;
    float open = 0;
    int currPos=1,prevPos=1;

    typedef struct{
        // int * nextNode;
        float weight;
    }conn;
    typedef struct{
        float inValue;
        conn branches[4];
    }inputNode;

    typedef struct{
        float nodeValue;
        conn branches[3];
    }firstLayer;

    typedef struct{
        float outValue;
        conn branches[3];
    }outLayer;

    inputNode input[3];
    firstLayer layer1[4];
    outLayer out[3];

    // for(int i=0;i<3;i++){// input to layer connections
    //     for(int j=0;j<4;j++){
    //         input[i].branches[j].nextNode=&layer1[j];
    //     }
    // }
    // for(int i=0;i<4;i++){// layer to output connections
    //     for(int j=0;j<3;j++){
    //         layer1[i].branches[j].nextNode=&out[j];
    //     }
    // }
    
    // set inputs
    input[0].inValue=block;
    input[1].inValue=block;
    input[2].inValue=open;

    // Init weights input
    for(int i=0;i<3;i++){
        input[i].branches[0].weight = (rand() % 100 + 1);
        input[i].branches[1].weight = (rand() % 100 + 1);
        input[i].branches[2].weight = (rand() % 100 + 1);
        input[i].branches[3].weight = (rand() % 100 + 1);
    }
    
    // set layer1 value
    for(int i=0;i<4;i++){
        float sum=0;
        for(int j=0;j<3;j++){
            sum+=input[j].inValue*input[j].branches[j].weight;
        }
        layer1[i].nodeValue=sum/3;
    }

    // print layer1 values
    for(int i=0;i<4;i++){
        printf("%f \n", layer1[i].nodeValue);
    }

    // Init weights layer1
    for(int i=0;i<4;i++){
        layer1[i].branches[0].weight = 0.9;
        layer1[i].branches[1].weight = 0.5;
        layer1[i].branches[2].weight = 0.6;
    }

    //set out values
    for(int i=0;i<3;i++){
        float sum=0;
        for(int j=0;j<4;j++){
            sum+=layer1[j].nodeValue*layer1[j].branches[j].weight;
        }
        out[i].outValue=sum/3;
    }

    // print out values
    for(int i=0;i<3;i++){
        printf("%f \n", out[i].outValue);
    }

    // neuron output
    for(int i=0;i<3;i++){
        if(out[i].outValue > triger){
            printf("Out Neuron %d fired \n", i+1);
        }
    }

    // sdlkfmlsdflsdnf
    srand(time(0));
    printf("%d \n", rand());
    
return 0;
}