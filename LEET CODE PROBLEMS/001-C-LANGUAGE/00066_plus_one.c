// LEETCODE 66
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdio.h>
#include<stdlib.h>
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int i;
    for(i=digitsSize-1;i>=0;i--){   // for [1,2,3] condition
        if(digits[i]<9){
            digits[i]++;
            *returnSize=digitsSize;
            return digits;
        }
        else
            digits[i]=0;    // for [1,9] condition
    }
    // for [9],[9,9] conditions, calloc used beacuse it assign with 0
    int *ans=(int *)calloc((digitsSize+1),sizeof(int)); 
    ans[0]=1;
    *returnSize=digitsSize+1;
    return ans;
}
void printArray(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}
int main(){
    int arr[]={9,9},i;
    int size=sizeof(arr)/sizeof(int);

    int returnSize;
    int* result1 = plusOne(arr, size, &returnSize);
    printArray(result1, returnSize);
    

    return 0;
}
/*OUTPUT : [1, 0, 0] */