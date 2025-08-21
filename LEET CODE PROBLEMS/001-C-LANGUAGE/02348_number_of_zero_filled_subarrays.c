// LeetCode : 2348 : Number of Zero-Filled Subarrays

#include <stdio.h>

long long zeroFilledSubarray(int* nums, int numsSize) {
    long long count = 0;
    // In contiguous: 1st 0 add 1, 2nd 0 add 2, and so on...
    for(int i = 0; i < numsSize; i++) {
        int temp = 0; // initialize with 0 : increase before add with count
        while(i < numsSize && nums[i] == 0) {
            count += ++temp;
            i++;
        }
    }
    return count;
}

int main() {
    int arr1[] = {1, 3, 0, 0, 2, 0, 0, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Zero-filled subarrays: %lld\n", zeroFilledSubarray(arr1, n1)); 
    // Expected: 6 (two 0's -> 3 subarrays, another two 0's -> 3 subarrays)

    int arr2[] = {0, 0, 0};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Zero-filled subarrays: %lld\n", zeroFilledSubarray(arr2, n2)); 
    // Expected: 6 ( [0], [0], [0], [0,0], [0,0], [0,0,0] )

    int arr3[] = {2, 10, 2019};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("Zero-filled subarrays: %lld\n", zeroFilledSubarray(arr3, n3)); 
    // Expected: 0

    return 0;
}

/*OUTPUT :
..........
Zero-filled subarrays: 6
Zero-filled subarrays: 6
Zero-filled subarrays: 0
*/

/*Time Complexity : O(N)
Space Complexity : O(1)*/