// LEETCODE - 31 : Next Permutation
#include<stdio.h>

void swap(int *x, int *y) { //swap function using xor
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
}

void nextPermutation(int* nums, int numsSize) {
    int i,mark = -1;
    for(i=numsSize - 1; i>0; i--){
        if(nums[i]>nums[i-1]){
            mark = i - 1;
            break;
        }
    }
    if(i != 0){
        for(i=numsSize-1; i>0; i--){
            if(nums[i] > nums[mark]){
                swap(nums+i,nums+mark);
                break;
            }
        }
    }

    mark++;
    i= numsSize-1;
    // reversing for increasing order maintain
    while(mark < i){
        swap(nums+mark,nums+i);
        mark++;i--;
    }
 
}
int main() {
    int nums[] = {2,7,1,4};
    int size = sizeof(nums) / sizeof(nums[0]);

    nextPermutation(nums, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
/*OUTPUT: 2 7 1 4 */
/*Time Complexity : O(N)
Space Complexity : O(1)*/