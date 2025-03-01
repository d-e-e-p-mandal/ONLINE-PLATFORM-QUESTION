// LEETCODE - 201 Bitwise and of Numbers Range
#include <stdio.h>
int rangeBitwiseAnd(int left, int right) {// Function to compute bitwise AND of range [left, right]
    int shift = 0;
    while (left < right) {  
        left >>= 1;  // Right shift both numbers until they become equal
        right >>= 1;
        shift++;
    }
    return left << shift;  // Shift back to get the final result
}
int main() {
    int left, right;
    
    printf("Enter left and right values: ");
    scanf("%d %d", &left, &right);

    // Compute and display result
    int result = rangeBitwiseAnd(left, right);
    printf("Bitwise AND of range [%d, %d] is: %d\n", left, right, result);
    
    return 0;
}
/* OUTPUT :
Enter left and right values: 5 7
Bitwise AND of range [5, 7] is: 4 */

/*
METHOD - 2 : (SELF)
int rangeBitwiseAnd(int left, int right) {
    int mid1 = left + (right-left)/2;
    int mid2 = left + (mid1-left)/2;
    int mid3 = left + (right-mid2)/2;
    int mid4 = left + (mid2 - left)/2;
    int mid5 = left + (right-mid3)/2;
    int mid6 = left + (mid4 - left)/2;
    int mid7 = left + (right - mid5)/2;
    int mid8 = left + (mid6 - left)/2;
    int mid9 = left + (right - mid7)/2;

    return left & mid1 &mid2 &mid3 &mid4 &mid5 &mid6 & mid7 &mid8 &mid9 & right;
}
*/