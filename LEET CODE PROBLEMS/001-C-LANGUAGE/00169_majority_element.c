// Leetcode : 169 : Majority Element : Boyer-Moore Voting Algorithm
#include <stdio.h>

// Function to find the majority element
int majorityElement(int* nums, int numsSize) {
    int count = 0;
    int pick = 0;

    for(int i = 0; i < numsSize; i++) {
        if(count == 0) {         // Pick new candidate
            pick = nums[i];
            count = 1;
        }
        else if(nums[i] == pick) { // Matching current candidate
            count++;
        }
        else {
            count--;             // Mismatch
        }
    }

    return pick; // Assumes majority element always exists
}

// Driver code to test the function
int main() {
    int nums[] = {2, 2, 1, 1, 1, 2, 2};
    int size = sizeof(nums) / sizeof(nums[0]);

    int result = majorityElement(nums, size);
    printf("Majority element is: %d\n", result);

    return 0;
}