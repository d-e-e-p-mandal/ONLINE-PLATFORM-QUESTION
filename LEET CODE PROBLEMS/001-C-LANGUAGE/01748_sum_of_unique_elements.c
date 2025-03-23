#include <stdio.h>

int sumOfUnique(int* nums, int numsSize) {
    int i,hash[101]={0},sum=0;  //hash size 101 ,constraints given

    for(i=0;i<numsSize;i++) {
        hash[nums[i]]++;
    }

    for(i=0;i<numsSize;i++) {
        if(hash[nums[i]]==1){   //if element one time(unique) then add 
            sum += nums[i];
        }
    }

    return sum;
}

int main() {
    int nums[] = {1, 2, 3, 2, 4, 3, 5};  // Example array
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = sumOfUnique(nums, numsSize);
    printf("Sum of unique elements: %d\n", result);

    return 0;
}

/*OUTPUT : Sum of unique elements: 10 */
/*Time Colplexity : O(N)*/