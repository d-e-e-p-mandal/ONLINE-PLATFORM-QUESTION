// LEETCODE -2161 : Partition Array According to Given Pivot
#include <stdio.h>
#include <stdlib.h>

int* pivotArray(int* nums, int numsSize, int pivot, int* returnSize) {
    int* res = (int*)malloc(numsSize * sizeof(int));
    int x = 0, y = 0, z = 0, i;

    // First pass: Count elements < pivot and == pivot
    for (i = 0; i < numsSize; i++) {
        if (nums[i] < pivot) y++;
        else if (nums[i] == pivot) z++;
    }

    z += y;  // `z` now marks the start index for elements > pivot

    // Second pass: Place elements in correct order
    for (i = 0; i < numsSize; i++) {
        if (nums[i] < pivot) res[x++] = nums[i];  // Elements < pivot
        else if (nums[i] == pivot) res[y++] = nums[i];  // Elements == pivot
        else res[z++] = nums[i];  // Elements > pivot
    }

    *returnSize = numsSize;
    return res;
}

int main() {
    int nums[] = {9, 12, 5, 10, 14, 3, 10};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int pivot = 10;
    int returnSize;
    
    int* result = pivotArray(nums, numsSize, pivot, &returnSize);

    printf("Reordered array: ");
    for (int i = 0; i < returnSize; i++)
        printf("%d ", result[i]);
    printf("\n");

    free(result); // Free allocated memory
    return 0;
}
/* (chatgpt)
int* pivotArray(int* nums, int numsSize, int pivot, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    int index = 0;

    // First pass: Elements < pivot
    for (int i = 0; i < numsSize; i++)
        if (nums[i] < pivot)
            result[index++] = nums[i];

    // Second pass: Elements == pivot
    for (int i = 0; i < numsSize; i++)
        if (nums[i] == pivot)
            result[index++] = nums[i];

    // Third pass: Elements > pivot
    for (int i = 0; i < numsSize; i++)
        if (nums[i] > pivot)
            result[index++] = nums[i];

    *returnSize = numsSize;
    return result;
}*/

/*OUTPUT : Reordered array: 9 5 3 10 10 12 14 */
/*Time Complexity : O(N)
Space Complexity : O(N)*/