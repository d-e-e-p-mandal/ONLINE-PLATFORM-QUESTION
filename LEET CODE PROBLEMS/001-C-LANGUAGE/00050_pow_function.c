// LEET CODE QUESTION 50
#include<stdio.h>
double myPow(double x, int n) {
    double res = 1.0 ;
    if(n==0 || x == 1 ) 
        return 1;
    long long int N=n;
    if(N<0){    //if n is -ve number
        N=-1*N;
        x=1/x;
    }

    while(N>0){
        if(N%2==1)
            res*=x;
        x*=x;
        N/=2;    
    }
   return res;
}
int main(){
    double x;
    int n;
    printf("Enter number : ");
    scanf("%lf",&x);
    printf("Enter power number : ");
    scanf("%d",&n);
    printf("Result : %lf\n",myPow(x,n));
    
    return 0;
}
/*
OUTPUT :
Enter number : 2
Enter power number : 10
Result : 1024.000000
*/