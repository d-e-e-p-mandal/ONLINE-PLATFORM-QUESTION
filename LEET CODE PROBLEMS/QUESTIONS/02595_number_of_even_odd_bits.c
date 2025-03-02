//LEETCODE - 2595 Number of Even and Odd Bits 
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int* evenOddBit(int n, int* returnSize) {
    int odd = 0, even = 0, i = 0;
    *returnSize = 2;
    int *arr = (int *)malloc(*returnSize * sizeof(int)); // arr[0] = even, arr[1] = odd

    while (n > 0) {
        if ((i & 1) == 0 && (n & 1) == 1)   // Counting bits at even indices
            even++;     
        else if ((i & 1) == 1 && (n & 1) == 1)  // Counting bits at odd indices
            odd++;
        i++;
        n >>= 1; // Right shift n
    }
    
    arr[0] = even; 
    arr[1] = odd;
    return arr; 
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int returnSize;
    int* result = evenOddBit(n, &returnSize);

    printf("Even bits: %d\n", result[0]);
    printf("Odd bits: %d\n", result[1]);

    free(result); // Free allocated memory
    return 0;
}
/*OUTPUT : 
Enter a number: 50
Even bits: 1
Odd bits: 2  */

/*Time Complexity : O(Log(N))
Space Complexity : O(1)*/