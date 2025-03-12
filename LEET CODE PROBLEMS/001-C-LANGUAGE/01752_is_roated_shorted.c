// LEETCODE QUESTION 1752
#include<stdio.h>
#include<stdbool.h>
bool check(int* nums, int numsSize) {
    int i,x;
    for(i=0;i<numsSize-1;i++){
        if(nums[i]>nums[i+1])
            break;
    }
    x=++i;
    while(i<numsSize){
        if(nums[0]<nums[i] )
            return false;
        if(x<i && (nums[i-1]>nums[i]))
            return false;
        i++;
    }
    return true;
}
int main(){
    int nums[] = {3, 4, 5, 1, 2};
    int numsSize = sizeof(nums)/sizeof(int);
    printf("%s\n",check(nums,numsSize)?"true":"false");
    return 0;
}
/* true */