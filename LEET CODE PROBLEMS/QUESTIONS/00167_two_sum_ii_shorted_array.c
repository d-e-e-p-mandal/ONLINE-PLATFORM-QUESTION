// LEETCODE - 167 : Two Sum II - Input Two Shorted Array
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

/*(self - my)
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int *arr = (int *)malloc(2*sizeof(int));
    int x=0,y=numbersSize-1;
    int sum = numbers[x]+numbers[y];    // using two pointer approach

    while(sum!=target) {
        if(sum>target)      
            y--;
        else if(sum<target)
            x++;
        sum = numbers[x]+numbers[y];  
    }

    *returnSize = 2;    //two index return
    arr[0]=x+1;     //returning index start from 1
    arr[1]=y+1;
    return arr;
} */
int *twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    if (numbersSize < 2) {  // Validate input
        *returnSize = 0;
        return NULL;
    }

    int *arr = (int *)malloc(2 * sizeof(int));
    if (!arr) {  // Check for memory allocation failure
        *returnSize = 0;
        return NULL;
    }

    int x = 0, y = numbersSize - 1;

    while (x < y) {
        int sum = numbers[x] + numbers[y];  // Compute sum only when necessary
        
        if (sum == target) {
            arr[0] = x + 1;  // Convert zero-based index to one-based index
            arr[1] = y + 1;
            *returnSize = 2;
            return arr;
        } 
        else if (sum > target) {
            y--;  // Move right pointer leftward
        } 
        else {
            x++;  // Move left pointer rightward
        }
    }

    // If no solution is found, free memory and return NULL
    free(arr);
    *returnSize = 0;
    return NULL;
}

// Test function
void printResult(int* result, int returnSize) {
    if (returnSize == 2) {
        printf("Indices: [%d, %d]\n", result[0], result[1]);
    } else {
        printf("No solution found.\n");
    }
}

int main() {
    int numbers[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
    
    int *result = twoSum(numbers, 4, target, &returnSize);
    printResult(result, returnSize);
    
    free(result);  // Free allocated memory
    return 0;
}
/*OUTPUT : Indices: [1, 2] */
/* Time Complexity : O(N)
Space Complexity : O(1) */