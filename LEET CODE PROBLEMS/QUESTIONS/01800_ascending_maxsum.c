// LEET CODE QUESTION 1800
#include<stdio.h>
int maxAscendingSum(int* nums, int numsSize) {
    int i,currentSum,maxSum;
    currentSum=maxSum=nums[0];
    for(i=1;i<numsSize;i++){
        currentSum=(nums[i]>nums[i-1])?currentSum+nums[i]:nums[i]; // check ascending
        maxSum=(maxSum<currentSum)?currentSum:maxSum;   //store maximum sum
    }
    return maxSum;
}
int main(){
    int n=6;
    int arr[]={10,20,30,5,10,50};
    printf("Maximum sum : %d\n",maxAscendingSum(arr,n));
    
    return 0;
}
/* OUTPUT : Maximum sum : 65 */