#include<stdio.h>
#include<stdlib.h>
int main(){// WAP to open an existing text file and copy it's contents to a newly created text file
    FILE *fp1=fopen("test.txt","r");
    FILE *fp2=fopen("test2.txt","r");
    FILE *fpO=fopen("concOut.txt", "w");
    char c;
    while(c != EOF){
        c=getc(fp1);
        if(c != EOF)
            fputc(c, fpO);
        printf("%c", c);
    }
    c = 'F';
    while(c != EOF){
        c=getc(fp2);
        if(c != EOF)
            fputc(c, fpO);
        printf("%c", c);
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fpO);
return 0;
}