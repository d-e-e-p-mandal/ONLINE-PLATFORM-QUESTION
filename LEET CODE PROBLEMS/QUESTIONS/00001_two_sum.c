// LEETCODE QUESTION 1 : Two Sum
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdio.h>
#include<stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *result,i,j;
    result=(int *)malloc(2*sizeof(int));   //memory allocate by malloc
    for(i=0;i<numsSize-1;i++){
        for(j=i+1;j<numsSize;j++)
            if(nums[i]+nums[j]==target){
                result[0]=i;
                result[1]=j;
                *returnSize=2;
                return result; // return address of result result
            }
    }
    *returnSize=0;
    return 0; 
}
int main(){
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
    
    int* result = twoSum(nums, 4, target, &returnSize);
    
    if (returnSize == 2) {
        printf("Indices: [%d, %d]\n", result[0], result[1]);
        free(result);
    } else {
        printf("No solution found.\n");
    }
    return 0;
}
/* OUTPUT : Indices: [0, 1] */