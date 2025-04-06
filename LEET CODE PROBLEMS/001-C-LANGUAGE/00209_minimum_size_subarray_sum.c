// LEETCODE 209 : Minimum Size Subarray Sum
#include <stdio.h>
int minSubArrayLen(int target, int* nums, int numsSize) {
    int left,right,sum=0;
    left=right=0;

    int len, minLen = 2147483647;   //Maximum Integer = 2147483647

    while(left < numsSize ) {
        if(sum < target) {
            if(right == numsSize)
                break;
            sum += nums[right++];
        }
        else {
            len = right - left;
            if(minLen > len)minLen = len;

            sum -= nums[left++];
        } 
    }

    if(minLen == 2147483647) return 0;  //if target not found return zero

    return minLen;

}

int main() {
    int nums[] = {2, 3, 1, 2, 4, 3};
    int target = 7;
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = minSubArrayLen(target, nums, numsSize);

    if (result == 0)
        printf("No valid subarray found.\n");
    else
        printf("Minimum length of a subarray with sum >= %d is %d.\n", target, result);

    return 0;
}