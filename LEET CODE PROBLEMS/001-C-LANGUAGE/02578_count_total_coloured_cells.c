// LEETCODE - 2579 : Count Total Number of Colored Cells
#include <stdio.h>

long long coloredCells(int n) {
    return (unsigned long long)n*n+(unsigned long long)(n-1)*(n-1);
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Total colored cells: %lld\n", coloredCells(n));
    return 0;
}
/*OUTPUT : Enter n: 4
Total colored cells: 25*/

/* return long long)n*n+(long long)(n-1)*(n-1);
return 1LL * 1 + 1LL * 2 * n * (n - 1); // 1LL means (long long 1)
*/