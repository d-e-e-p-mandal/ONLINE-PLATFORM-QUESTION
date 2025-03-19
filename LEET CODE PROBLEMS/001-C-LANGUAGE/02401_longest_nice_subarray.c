// LEETCODE - 2401 : Longest Nice Subarray
#include <stdio.h>

int longestNiceSubarray(int* nums, int numsSize) {
    int i=1,count = 1,maxCount = 1,left = 0, temp = nums[0];

    while(i<numsSize){
        if((temp & nums[i]) == 0){  
            temp = temp | nums[i];  // OR operation for adding bit
            count++ ;
            i++; 
        }
        else {  // shrink from left and value of i not be increase
            temp ^= nums[left];
            left++;
            count--;
        }
        maxCount = (maxCount < count) ? count : maxCount;   // maxlength storing
    }
    return maxCount;
}

int main() {
    int nums[] = {1, 3, 8, 48, 10};
    int size = sizeof(nums) / sizeof(nums[0]);

    printf("Longest Nice Subarray Length: %d\n", longestNiceSubarray(nums, size));
    return 0;
}
/*Method : 2 (c - same logic of method 1)

int longestNiceSubarray(int* nums, int numsSize) {
    int maxLength = 0, mask = 0, l = 0;
    
    for (int r = 0; r < numsSize; r++) {
        // Adjust left pointer to maintain the "nice" condition
        while ((mask & nums[r]) != 0) {
            mask ^= nums[l];  // Remove nums[l] from mask
            l++;
        }
        
        // Include the new number in the mask
        mask |= nums[r];
        
        // Update the maximum subarray length
        if (r - l + 1 > maxLength) {
            maxLength = r - l + 1;
        }
    }
    
    return maxLength;
}*/

/*Method - 3 : (using sum)
int longestNiceSubarray(int* nums, int numsSize) {
    int i=0,count = 0,maxCount = 0,left = 0;
    int sum = 0,xorSum = 0;
    while(i<numsSize){
        sum += nums[i]; 
        xorSum ^= nums[i];
        count++;
        while(sum != xorSum){  
            // shrink from left and value of i not be increase
            sum -= nums[left]; 
            xorSum ^= nums[left]; 
            left++;
            count--;
        }
        i++;
        maxCount = (maxCount < count) ? count : maxCount;   // maxlength storing
    }
    return maxCount;
}*/

/*OUTPUT :Longest Nice Subarray Length: 3 */

/*Time Complexity : O(N)
Space Complexity : O(1)*/