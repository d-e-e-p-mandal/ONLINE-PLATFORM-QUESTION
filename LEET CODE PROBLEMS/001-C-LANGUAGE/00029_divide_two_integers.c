// LEETCODE 29 : Divide Two Integers
#include <stdio.h>
#include <limits.h>

int sign(int dividend, int divisor){    // fuction determine the sign
    if((dividend > 0 && divisor > 0) || (dividend < 0 && divisor <0))
        return 1;

    return -1;
}

int divide(int dividend, int divisor) {
    if(dividend == -2147483648 && divisor == -1) return 2147483647; //overflow case 

    int count = 0;
    long res = 0;

    int s = sign(dividend, divisor);
    long a = (long)dividend;
    long b = (long)divisor;
    
    if(dividend < 0) a = -a;
    if(divisor < 0 )b = -b;

    int x = 0;

    while(a >= b){
        count = 0;
        while( a >= (b<<(count+1))){  // long long for maximum integer number
            count++;
        }
        res += ((long long)1<<count); 
        a -= (b<<(count)); // (divior * (1<< x)) == (divisor << x)
        
    }
    return  res * s;
}
int main() {
    int dividend, divisor;

    dividend = 10;
    divisor = 3;
    printf("%d / %d = %d\n", dividend, divisor, divide(dividend, divisor));

    return 0;
}