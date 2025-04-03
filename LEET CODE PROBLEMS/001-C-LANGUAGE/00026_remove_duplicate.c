#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    int left=0,right;
    for( right=1;right<numsSize;right++) {
        if(nums[left] !=nums[right]){   
            nums[++left] = nums[right]; //change value
        }
    }
    return left+1;
}

void printArray(int* nums, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main() {
    int nums[] = {1, 1, 2, 2, 3, 4, 4, 5};
    int size = sizeof(nums) / sizeof(nums[0]);

    int newLength = removeDuplicates(nums, size);
    
    printf("New length: %d\n", newLength);
    printf("Modified array: ");
    printArray(nums, newLength);

    return 0;
}