// Leetcode : 3392 Count Subarrays of Length Three With a Condition
#include <stdio.h>

int countSubarrays(int* nums, int numsSize) {
    if (numsSize < 3) return 0; // If array size is less than 3, no valid triplets exist.

    int count = 0;

    for (int i = 0; i <= numsSize - 3; i++) {
        // Check if the middle element is even and follows the given condition
        if ((nums[i+1] % 2 == 0) && (nums[i] + nums[i+2] == 2 * nums[i+1])) {
            //(2 * (nums[i] + nums[i+2]) == (nums[i+1]))
            //((nums[i+1] & 1 ) == 0  && (nums[i] + nums [i+2] ) ==  (nums[i+1] >>1) )
            count++;
        }
    }
    
    return count;
}

int main() {
    int nums[] = {4, 8, 4, 2, 6};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = countSubarrays(nums, numsSize);
    printf("Count of valid subarrays: %d\n", result);

    return 0;
}