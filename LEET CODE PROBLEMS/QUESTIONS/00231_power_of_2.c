// LEET CODE QUESTION 231
#include<stdio.h>
int isPowOf2(int n){
    return (n>0 && !(n & (n-1)));
}
int main(){
    int n;
    printf("Enter number two check the number is power of 2 : ");
    scanf("%d",&n);
    if(isPowOf2(n))
        printf("Your entered number is power of 2. \n");
    else 
        printf("Your entered number is not power of 2. \n");
    return 0;
}
/*OUTPUT : 
1. Enter number two check the number is power of 2 : 16
   Your entered number is power of 2.
2. Enter number two check the number is power of 2 : 0
   Your entered number is not power of 2. 
*/