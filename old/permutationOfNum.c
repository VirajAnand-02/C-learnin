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
    int n, i=0;
    char ch[10000];
    printf("Input number : ");
    scanf("%d", &n);
    while(n != 0){
        sscanf(&ch[i],"%c",n%10);
        n /= 10;
        i++;
    }
    permute(ch, 0, 4 - 1);
    
    return 0;
}