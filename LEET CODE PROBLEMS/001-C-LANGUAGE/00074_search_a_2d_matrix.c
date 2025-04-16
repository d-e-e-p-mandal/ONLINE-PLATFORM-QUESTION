// LEETCODE Question - 74 : Search a 2D Matrix 
#include <stdio.h>
#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    if (matrixSize == 0 || matrixColSize[0] == 0) 
        return false;

    int low = 0, high = matrixSize - 1, mid, row;

    // Binary search to find the correct row
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (matrix[mid][0] <= target)  
            low = mid + 1;
        else
            high = mid - 1;
    }
    row = high;  // The last valid row where matrix[row][0] <= target

    if (row < 0) return false; // Target is smaller than the first element in the matrix

    // Binary search within the selected row
    low = 0;
    high = matrixColSize[row] - 1;

    while (low <= high) {
        mid = low + (high - low) / 2;
        if (matrix[row][mid] == target)
            return true;
        else if (matrix[row][mid] < target)
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return false;
}

int main() {
    int matrixData[3][4] = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int* matrix[3] = {matrixData[0], matrixData[1], matrixData[2]};
    int matrixColSize[3] = {4, 4, 4}; 

    int target = 3;

    if (searchMatrix(matrix, 3, matrixColSize, target))
        printf("Target %d found in matrix.\n", target);
    else
        printf("Target %d not found in matrix.\n", target);

    return 0;
}
/*OUTPUT : Target 3 found in matrix. */

/*Time Complexity : O(log(m) + log(n)) = O(log(mn))
Space Complexity : O(1)*/
/* Method : (c)
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int m = matrixSize;
    int n = *matrixColSize;
    int left = 0, right = m * n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int mid_value = matrix[mid / n][mid % n];

        if (mid_value == target)
            return true;
        else if (mid_value < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}*/

/*(extra : not recomended)
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int low=0,high=matrixSize-1,mid,row;
    mid=(low+high)/2;
    while(low<=high){
        if(matrix[mid][0]>target)
            high=mid-1;
        else if(matrix[mid][0]<target)
            low=mid+1;
        else
            break;
        mid=(low+high)/2;
    }
    row = mid;

    low=0;
    high=*matrixColSize-1;
    while(low<=high){
        mid=(low+high)/2;
        if(matrix[row][mid]==target){
            return true;
        }
        if(matrix[row][mid]>target)
            high=mid-1;
        else
            low=mid+1;
    }
    return false;
}*/