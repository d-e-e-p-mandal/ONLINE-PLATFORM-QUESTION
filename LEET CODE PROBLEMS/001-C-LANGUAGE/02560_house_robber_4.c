// LEETCOE - 2560 : House Robber IV
#include<stdio.h>

//Method 1 : (Method 2 is more optimise)
int isPossible(int *nums, int numsSize, int k, int mid) {
    int i;
    for(i=0; i<numsSize; i++) {
        if(nums[i] <= mid){
            k--;
            i++; // for skip adjacent
        }
        if(k==0)return 1;
    }
    return 0;
}
int minCapability(int* nums, int numsSize, int k) {
    int low  = 1 ,high = 2147483647, mid; //1 <= nums[i] <= 1e9

    while(low <= high){  //binary search from 1 to 2147483647 to find minimum 
        mid = low + (high - low)/2;
        if(isPossible(nums,numsSize,k,mid)){ // if k-1 time, amount are present in array which is less than or equal to mid, then it can be result ..... then we find less of it amount is possible and so on
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return low;
}

int main() {
    int nums[] = {2, 3, 5, 9}; // Example test case
    int k = 2;
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = minCapability(nums, numsSize, k);
    printf("Minimum possible maximum amount: %d\n", result);

    return 0;
}
/*Method : 2 
int isPossible(int *nums, int numsSize, int k, int mid) {
    int i;
    for(i=0; i<numsSize; i++) {
        if(nums[i] <= mid){
            k--;
            i++; // for skip adjacent
        }
        if(k==0)return 1;
    }
    return 0;
}
int minCapability(int* nums, int numsSize, int k) {
    int i,low  = nums[0] ,high = nums[0], mid;
    //ans will be between least amount and highest amount 
    for(i=1; i<numsSize; i++) {
        if(nums[i] < low) low = nums[i];
        if(nums[i] > high) high = nums[i];
    }


    while(low <= high){  //binary search from least amount to highest amount in array
        mid = low + (high - low)/2;
        if(isPossible(nums,numsSize,k,mid)){ // if k-1 time, amount are present in array which is less than or equal to mid, then it can be result ..... then we find less of it amount is possible and so on
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return low;
}*/


/*OUTPUT : Minimum possible maximum amount: 5 */
/*Time Complexity : O(NlogN) */