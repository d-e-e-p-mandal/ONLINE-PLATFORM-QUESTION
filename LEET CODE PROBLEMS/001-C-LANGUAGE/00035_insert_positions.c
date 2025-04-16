// LEETCODE QUESTION 35
#include<stdio.h>

int searchInsert(int* nums, int numsSize, int target) {//binary search 
    
    int left = 0, right = numsSize - 1, mid;
    while(left <= right) {
        mid = left + (right - left)/2;
        if(nums[mid] == target)
            return mid; 
        else if(nums[mid] < target)
            left = mid + 1;
        else 
            right = mid - 1;
    }
    return left; // if target does not match any element in then return just less element index
}

int main(){
    int arr[7]={0,1,3,4,5,6,8};
    int size=sizeof(arr)/sizeof(int);
    int target = 5;
    printf("Positions : %d \n",searchInsert(arr,size,target));
    return 0;
}
/* Positions : 4 */
/*Time Complexity : O(LogN)
Space Comp*/

int searchInsert(int* nums, int numsSize, int target) { //linear search
    int i;
    for(i=0;i<numsSize;i++)
        if(nums[i]>=target)break;
    return i;
}