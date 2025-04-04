// LEETCODE -977 : Square of Sorted Array

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int firstNonNeg(int *nums, int numsSize) {
    int i;
    for(i=0;i<numsSize;i++) {
        if(nums[i]>=0)
            return i;
    }
    return i - 1;
}

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int i = 0;
    int r = firstNonNeg(nums,numsSize); 
    int l = r - 1;
    * returnSize = numsSize;

    int *res = (int *)malloc(numsSize * sizeof(int)); 
    
    while(l>=0 && r<=numsSize-1) {
        if(-nums[l] < nums[r]) {
            res[i++] = nums[l]*nums[l];
            l--;
        }
        else{
            res[i++] = nums[r]*nums[r];
            r++;
        }
    }
    while(l>=0) {   //if left element remaining
        res[i++] = nums[l]*nums[l];
        l--;
    }

    while(r<numsSize){  //if right element remaining
        res[i++] = nums[r]*nums[r];
        r++;
    }
    return res;
}



int main() {
    int nums[] = {-7, -3, 2, 3, 11};
    int size = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    
    int* result = sortedSquares(nums, size, &returnSize);

    printf("Result: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}
/*
Method - 2 :
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * numsSize);
    int left = 0, right = numsSize - 1;
    int pos = numsSize - 1;

    while (left <= right) {
        int leftSq = nums[left] * nums[left];
        int rightSq = nums[right] * nums[right];

        if (leftSq > rightSq) {
            result[pos--] = leftSq;
            left++;
        } else {
            result[pos--] = rightSq;
            right--;
        }
    }

    *returnSize = numsSize;
    return result;
}*/