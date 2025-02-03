// LEETCODE QUESTION 3105
#include<stdio.h>
int longestMonotonicSubarray(int* nums, int numsSize) {
    int i,countInr=1,countDer=1,resInr=1,resDer=1;
    for(i=0;i<numsSize-1;i++){
        if(nums[i]<nums[i+1])   // check increasing
            countInr++;
        else
            countInr=1;
        resInr=(resInr<countInr)?countInr:resInr;   // max Increasing

        if(nums[i]>nums[i+1])   // check decreasing
            countDer++;
        else
            countDer=1;
        resDer=(resDer<countDer)?countDer:resDer;   //max decreasing
    }
    if(resInr>resDer)
        return resInr;
    return resDer;
}
int main(){
    int arr[]={1,4,3,3,2};
    int size=sizeof(arr)/sizeof(int);
    printf("Maximum subarray is : %d \n",longestMonotonicSubarray(arr,size));
    return 0;
}
/* OUTPUT : Maximum subarray is : 2 */