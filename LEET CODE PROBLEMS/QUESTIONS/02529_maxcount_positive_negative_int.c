//LEETCODE - 2529 : Maximum Count of Positive Integer and Negative Integer
#include <stdio.h>

int maximumCount(int* nums, int numsSize) {  //(mycode)

    int low = 0,high = numsSize - 1,mid;
    int totalNegative,totalPositive;

    // finding total negative number
    int target = -1;   // nearest to zero and negative
    while(low <= high) {
        mid = low + (high - low)/2;
        if(nums[mid] <= target)
            low = mid + 1;
        else 
            high = mid - 1;
    }
    totalNegative = low - 0;

    // finding total positive number
    low = 0;
    high = numsSize - 1;
    target = 1;     //nearest to zero and positive
    while(low <= high) {
        mid = low + (high - low)/2;
        if(target <= nums[mid])
            high = mid - 1;
        else  
            low = mid + 1;
    }
    totalPositive = numsSize - high - 1;

    return (totalNegative > totalPositive) ? totalNegative : totalPositive;
}

int main() {
    int nums[] = {-5, -3, -1, 0, 0, 2, 3, 7};
    int n = sizeof(nums) / sizeof(nums[0]);

    printf("Maximum count: %d\n", maximumCount(nums, n));
    return 0;
}
/*Method 2 : (c)
int lowerBound(int arr[], int n, int target) {
    int left = 0, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int upperBound(int arr[], int n, int target) {
    int left = 0, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= target)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int maximumCount(int arr[], int n) {
    int negCount = lowerBound(arr, n, 0);     // First index of 0 (count of negative numbers)
    int posCount = n - upperBound(arr, n, 0); // Count of positive numbers
    return (negCount > posCount) ? negCount : posCount;
}*/

/*Time Complexity : O(logN)
Space Complexity : o(1)*/