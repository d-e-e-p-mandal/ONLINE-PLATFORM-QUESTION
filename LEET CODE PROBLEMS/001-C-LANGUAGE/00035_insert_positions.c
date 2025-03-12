// LEETCODE QUESTION 35
#include<stdio.h>
int searchInsert(int* nums, int numsSize, int target) {
    int i;
    for(i=0;i<numsSize;i++)
        if(nums[i]>=target)break;
    return i;
}
int main(){
    int arr[7]={0,1,3,4,5,6,8};
    int size=sizeof(arr)/sizeof(int);
    int target = 5;
    printf("Positions : %d \n",searchInsert(arr,size,target));
    return 0;
}
/* Positions : 4 */