//LEETCODE - 1342 : Number of Steps to Reduce a Number to Zero
#include <stdio.h>

int numberOfSteps(int num) {
    if(!num)return num; //if num = 0
    unsigned int count = 0;
    
    while(num) {
        if(num & 1 )
            count += 2; // for odd 
        else
            count++;    //for even
        num>>=1;
    }
    return count - 1;
}

int main() {
    int num = 14;
    printf("Steps to reduce %d to zero: %d\n", num, numberOfSteps(num));
    return 0;
}
/*Method : chatgpt
int numberOfSteps(int num) {
    if (num == 0) return 0;
    return __builtin_popcount(num) + 31 - __builtin_clz(num); //popcount = 1 , clz = 0
}*/

/*TIME COMPLEXITY : O(logN)
SPACE COMPLEXITY :O(1)*/