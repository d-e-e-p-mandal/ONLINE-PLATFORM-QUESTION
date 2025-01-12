//LEET CODE QUESTION 7 USING ONLY POINTER
#include<stdio.h>
#include<stdlib.h>
int *reverse(int *x){
    int *rev,*n; //copy x in n for don't change the original value
    rev=(int *) malloc(sizeof(int));
    n=(int *) malloc(sizeof(int));
    *rev=0;
    *n=*x;
    while(*n){
        if(*rev>2147483647/10 || *rev<-2147483648/10) //check overflow condition for range of integer and pow(2,31)=2147483648
            return 0;
        *rev=((*rev)*10)+(*n%10);
        *n/=10;
    }
    free(n);
    return rev; //final result
} 
int main(){
    int *n=(int *)malloc(sizeof(int));
    printf("Enter number : ");
    scanf("%d",n);
    int *a;
    a=reverse(n); // a pointing that memory which is allocated by rev
    printf("Reverse is : %d\n",*a);
    //printf("Reverse is : %d\n",*reverse(n)); //both are same, to free memory use a
    free(n);
    free(a);
    return 0;
}
