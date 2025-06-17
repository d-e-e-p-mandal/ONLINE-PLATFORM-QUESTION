//LeetCode : Maximum Difference Between Increasing Elements

#include <stdio.h>

int maximumDifference(int* nums, int numsSize) {
    int i,diff = -1,max=-1,minIndex = 0;
    for(i=1; i<numsSize; i++){
        if(nums[minIndex] >= nums[i]) //if current element is less than previous element
            minIndex = i;
        else
            diff = nums[i]-nums[minIndex];//calulate difference

        if(max < diff) max = diff;//store max diff
    }   
    return max;   
}

int main() {
    int nums[] = {7, 1, 5, 4};
    int size = sizeof(nums) / sizeof(nums[0]);

    int result = maximumDifference(nums, size);
    printf("Maximum Difference: %d\n", result);

    return 0;
}

/* Output : Maximum Difference: 4 */
/* Time Complexity : O(N) 
Space Complexity : O(1)*/