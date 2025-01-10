#include<stdio.h>
int reverse(int x){
    int rev=0,n=x; //copy x in n
    while(n){
        if(rev>2147483647/10 || rev<-2147483648/10) //check overflow condition for range of integer and pow(2,31)=2147483648
            return 0;
        rev=(rev*10)+(n%10);
        n/=10;
    }
    return rev; //final result
}
int main(){
    int n;
    printf("Enter number : ");
    scanf("%d",&n);
    printf("Reverse is : %d\n",reverse(n));
    return 0;
}