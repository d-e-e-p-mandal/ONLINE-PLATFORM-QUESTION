//LEETCODE - 2595 Divide an Array Into Subarrays With Minimum Cost I
#include <stdio.h>

int minimumCost(int* nums, int numsSize) {
    int i;
    int min2, min3;

    // Initialize min2 and min3 using nums[1] and nums[2]
    if (nums[1] < nums[2]) {
        min2 = nums[1];
        min3 = nums[2];
    } else {
        min2 = nums[2];
        min3 = nums[1];
    }

    // Find the two smallest elements from index 1 to numsSize-1
    for (i = 3; i < numsSize; i++) {
        if (nums[i] < min2) {
            min3 = min2;
            min2 = nums[i];
        }
        else if (nums[i] < min3) {
            min3 = nums[i];
        }
    }

    // Return sum of first element and two minimum elements
    return nums[0] + min2 + min3; // nums[0] is always cost of 1st subarray
}

int main() {
    int n;
    printf("Enter N : ");
    scanf("%d", &n);

    int nums[n];
    printf("Enter array Element : \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("%d\n", minimumCost(nums, n));

    return 0;
}

/*
-----------------------------------------
Enter N : 5
Enter array Element : 
1 2 3 4 5
6

Explanation:
nums[0] = 1
Two smallest elements from remaining array = 2 and 3
Total cost = 1 + 2 + 3 = 6

-----------------------------------------
Time Complexity:
O(n)
Reason:
Single pass to find the two minimum elements.

Space Complexity:
O(1)
Reason:
Only constant extra variables used.

-----------------------------------------
*/