// LEETCODE - 189 :Rotate Array
#include <stdio.h>

void swap(int *x, int *y) { // Swap two integers
    int temp = *x;
    *x = *y;
    *y = temp;
}

void rev(int *nums, int left, int right) { // Reverse elements between left and right indices in the array
    while(left < right) {
        swap(nums + left, nums + right);
        left++;
        right--;
    }
}

// Rotate the array to the right by k steps
void rotate(int* nums, int numsSize, int k) {
    if (numsSize == 0 || k <= 0) return;

    k %= numsSize;  // Handle cases where k > numsSize
    rev(nums, 0, numsSize - 1);      // Reverse the whole array
    rev(nums, 0, k - 1);             // Reverse the first k elements
    rev(nums, k, numsSize - 1);      // Reverse the remaining elements
}

void printArray(int* arr, int size) {   // Function to print the array
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 3;

    printf("Original array:\n");
    printArray(nums, numsSize);

    rotate(nums, numsSize, k);

    printf("Array after rotating right by %d steps:\n", k);
    printArray(nums, numsSize);

    return 0;
}