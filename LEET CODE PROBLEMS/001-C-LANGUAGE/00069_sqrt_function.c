// LEETCODE FUNCTION 69
// without built in fuction 
#include<stdio.h>
int mySqrt(int x) {
    long int i;   // take long for boundary case 
    for(i=0;i<=x;i++){
        if(i*i>x)   // if greter than x ,then return i-1
            break;
    }
    return i-1;
}
int main(){
    int x = 8;
    printf("Square root of %d: %d\n", x, mySqrt(x));
    return 0;
}
/* OUTPUT : Square root of 8: 2 */