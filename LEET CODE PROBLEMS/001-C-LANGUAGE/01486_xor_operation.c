// LEETCODE 1486 - XOR OPERATION
#include <stdio.h>
int oddPart(int n, int start){
    int res,last;
    last = start + (n-1)*2;
    if(last % 8 == 1 ) return last;
    if(last % 8 == 3 ) return 2;
    if(last % 8 == 5 ) return last+2;
    return 0;
}
int evenPart(int n, int start){
    int res,last;
    last = start + (n-1)*2;
    if(last % 8 == 2 ) return 2;
    if(last % 8 == 4 ) return last+2;
    if(last % 8 == 6 ) return 0;
    return last;
}
int xorOperation(int n, int start) {
    int r1=0,r2;
    if(start%2 == 0){   //even part
        if(start>2)
            r1 = evenPart(start/2,0);
        r2 = evenPart(n,start);
        return r1^r2;
    }
    //odd part
    if(start>1)
        r1 = oddPart(start/2,1);
    r2 = oddPart(n,start);
    return r1^r2;

}    
int main() {
    int n, start;
    printf("Enter the number of elements (n): ");
    scanf("%d", &n);
    printf("Enter the starting number (start): ");
    scanf("%d", &start);

    int result = xorOperation(n, start);
    printf("The XOR result is: %d\n", result);

    return 0;
}
/* OUTPUT :
Enter the number of elements (n): 4
Enter the starting number (start): 3
The XOR result is: 8
*/

/*
METHOD - 2 :
int xorFromZero(int x) {
    // XOR from 0 to x follows a pattern:
    // x % 4 == 0 -> x
    // x % 4 == 1 -> 1
    // x % 4 == 2 -> x + 1
    // x % 4 == 3 -> 0
    if (x % 4 == 0) return x;
    if (x % 4 == 1) return 1;
    if (x % 4 == 2) return x + 1;
    return 0;
}

int xorOperation(int n, int start) {
    // Use properties of XOR to compute efficiently
    int s = start / 2;
    int result = xorFromZero(s + n - 1) ^ xorFromZero(s - 1);
    
    if (start % 2 == 1) {
        return (result * 2) + n % 2; 
    }
    return result * 2;
}
*/