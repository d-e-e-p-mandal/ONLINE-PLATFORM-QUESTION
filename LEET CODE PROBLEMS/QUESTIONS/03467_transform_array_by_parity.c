// LEETCODE 3467 - Transform Array by Parity
#include <stdio.h>
#include <stdlib.h>
int* transformArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int *arr = (int *)malloc(numsSize * sizeof(int));
    int i, x = 0, y = numsSize - 1;

    // Fill the array with 0s on the left and 1s on the right
    for (i = 0; i < numsSize; i++) {
        if (nums[i] & 1)
            arr[y--] = 1;  // Odd numbers go to the right
        else
            arr[x++] = 0;  // Even numbers go to the left
    }
    return arr;
}
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int nums[] = {4, 3, 2, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* result = transformArray(nums, numsSize, &returnSize);

    printArray(result, returnSize); //display

    free(result); // Free allocated memory
    return 0;
}
/*OUTPUT : 0 0 1 1  */