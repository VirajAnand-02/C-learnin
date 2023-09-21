#include<stdio.h>
int nC_Pr(int n, int r, int ncr){
    int k=ncr, prev=ncr;
    if(r > n)
        return -1;
    if(ncr)
        k = r;
    if(r == 0)
        return 1;
    return (n*(nC_Pr(n-1, r-1, prev)))/k;
}
int main(){
    int n, r, choice;
    printf("Enter number, N : ");
    scanf("%d", &n);
    printf("Enter number, R : ");
    scanf("%d", &r);
    printf("Select Option-\n\t1) nCr\n\t2) nPr\n");
    scanf("%d", &choice);
    if(choice == 1)
        printf("%d\n", nC_Pr(n, r, 1));
    else if(choice == 2)
        printf("%d\n", nC_Pr(n, r, 0));
    else
        printf("Invalid input");
return 0;
}