//LeetCode : 42 : Trapping Rain Water : Optimal Solution
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int totalWater = 0;

        // (left < right ) at max height exit the loop
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax) {  // update or store water 
                    leftMax = height[left]; 
                } else {
                    totalWater += leftMax - height[left];
                }
                left++;
            } else {
                if (height[right] >= rightMax) {  // update or store water 
                    rightMax = height[right];
                } else {
                    totalWater += rightMax - height[right];
                }
                right--;
            }
        }

        return totalWater;
    }
};

int main() {
    Solution sol;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int result = sol.trap(height);
    cout << "Total trapped water: " << result << endl;
    return 0;
}
/*
OUTPUT :
Enter height size : 6
Enter block height : 
4       2       0       3       2       5
Total water is : 9
*/
/* Time Complexity : O(N)
Space Complexity : O(1)*/