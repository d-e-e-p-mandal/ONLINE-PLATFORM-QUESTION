//LEET CODE QUESTION 263
#include<stdio.h>
#include<stdbool.h>
bool isUgly(int n) {
    if(n<1)
        return false;
    while(n){
        if(n==1)    // one hos only one prime factor 1
            return true;
        else if(n%2==0)
            n/=2;
        else if(n%3==0)
            n/=3;
        else if(n%5==0)
            n/=5;
        else
            return false;
    }
    return false;
}
int main(){
    int n;
    printf("Enter number to check ugly number : ");
    scanf("%d",&n);
    if(isUgly(n))
        printf("You entered ugly nymber.\n");
    else 
        printf("Your entered number is not ugly.\n");
    return 0;
}
/*
OUTPUT :
Enter number to check ugly number : 14
Your entered number is not ugly.
*/