// LEETCODE 338  COUNTING BITS
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
int* countBits(int n, int* returnSize) {
    int i;
    *returnSize = n+1;
    int *arr = (int *)malloc((n+1)*sizeof(int));
    
    arr[0] = 0;
    for(i=1; i<=n; i++)
        arr[i] = arr[i>>1] + (i & 1);
    return arr;
}
int main() {
    int n = 10;
    int returnSize;
    int* result = countBits(n, &returnSize);

    printf("Counting bits up to %d:\n", n);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}
/* OUTPUT : 
Counting bits up to 10:
0 1 1 2 1 2 2 3 1 2 2 
*/


/*
METHOD : 2 
int* countBits(int n, int* returnSize) {
    int i;
    *returnSize = n+1;
    int *arr = (int *)malloc((n+1)*sizeof(int));
    
    arr[0] = 0;
    for(i=1; i<=n; i++)
        arr[i] = arr[i & (i-1)]+1;
    return arr;
}
*/