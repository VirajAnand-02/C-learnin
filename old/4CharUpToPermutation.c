#include<stdio.h>
#include<string.h>
void swap(char* x, char* y){
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void permute(char* a, int l, int r){
	int i;
	if (l == r)
		printf("%s\n", a);
	else {
		for (i = l; i <= r; i++) {
			swap((a + l), (a + i));
			permute(a, l + 1, r);
			swap((a + l), (a + i)); // backtrack
		}
	}
}
int main(){
    char ch[5];
    printf("Input 4 characters");
    scanf("%s", &ch);
    for(int i=0; i<4; i++){
        if(ch[i]<=122 && ch[i]>=97){
           ch[i] -= 32;
        }
    }
    permute(ch, 0, 4 - 1);
    
    return 0;
}