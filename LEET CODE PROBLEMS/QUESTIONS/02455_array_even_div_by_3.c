// LEETCODE QUESTION 2455
#include<stdio.h>
int averageValue(int* nums, int numsSize) {
    int sum=0,i,count=0;
    for(i=0;i<numsSize;i++)
        if(nums[i]!=0 && nums[i] % 6 == 0){
            sum+=nums[i];
            count++;
        }

    if(count == 0)return sum;
    return sum/count;
}
int main(){
    int arr[]={10,12,0,3,35,6};
    printf("average : %d\n",averageValue(arr,sizeof(arr)/sizeof(int)));
    return 0;
}