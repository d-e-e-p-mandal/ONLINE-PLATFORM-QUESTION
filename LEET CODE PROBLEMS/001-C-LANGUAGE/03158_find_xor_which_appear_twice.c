// LEETCODE - 3158 : Find the XOR of Numbers Which Appear Twice 
#include <stdio.h>

int duplicateNumbersXOR(int* nums, int numsSize) {
    int i, hash[51] = {0}, xor = 0;

    for(i = 0; i<numsSize; i++) {
        hash[nums[i]]++;
        if(hash[nums[i]] == 2)    // which is more than 2 that is one pair twice
            xor = xor ^ nums[i];
    }

    return xor;
}

int main() {
    int nums[] = {1, 2, 1, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = duplicateNumbersXOR(nums, numsSize);
    printf("The XOR of numbers appearing twice is: %d\n", result);
    return 0;
}
/*OUTPUT : The XOR of numbers appearing twice is: 1 */