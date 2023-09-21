#include<stdio.h>
#include<stdlib.h>
int main(){//WAP that creates a file and inserts some contents provided by the user at runtime
    FILE *fp=fopen("runtimeOut.txt","w");
    char str[10000];
    if(fp){
        printf("File Opened. press enter to write out to file\nInput Content : ");
        scanf("%s",&str);
        fprintf(fp, str);
    }
    printf("Writing Complete\n");
    fclose(fp);
return 0;
}