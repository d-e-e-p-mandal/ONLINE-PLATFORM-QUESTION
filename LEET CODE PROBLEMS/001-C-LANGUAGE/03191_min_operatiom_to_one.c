//LEETCODE - 3191 : Minimum Operations to Make Binary Array Elements Equal to One I
#include <stdio.h>

int minOperations(int* nums, int numsSize) {
    int i,count = 0;
    for(i=0;i<=numsSize - 3;i++) {
        if(nums[i]==0) {    // change three consecutive elements
        //    nums[i] ^= 1;   nums[i] = 1; (this line is not mandatory)
            nums[i+1] ^= 1;
            nums[i+2] ^= 1;
            count++;
        }
    }
    // if one of them of last two number is zero then return -1
    if(nums[numsSize - 2]==0  || nums[numsSize - 1]==0)
        return -1;
    
    return count;
}

int main() {
    int nums[] = {0, 1, 1, 1, 0, 0};
    int size = sizeof(nums) / sizeof(nums[0]);

    int result = minOperations(nums, size);
    printf("Minimum operations: %d\n", result);

    return 0;
}
/*OUTPUT : Minimum operations: 3 */
/*Time Complexity : O(N)
Space Complexity : O(1)*/