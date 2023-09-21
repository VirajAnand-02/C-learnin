#include<stdio.h>
#include<stdlib.h>
int main(){// WAP to open an existing text file and copy it's contents to a newly created text file
    FILE *fp=fopen("test.txt","r");
    FILE *wrtFp=fopen("copyOfText.txt","w");
    char c;
    while(c != EOF){
        c=fgetc(fp);
        if(c != EOF)
            fputc(c, wrtFp);
        printf("%c", c);
    }
return 0;
}