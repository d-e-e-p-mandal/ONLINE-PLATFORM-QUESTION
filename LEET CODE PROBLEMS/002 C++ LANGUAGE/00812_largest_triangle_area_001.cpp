// LeetCode : 812 : Largest Triangle Area : (Optimal Solution)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double area = 0.0;
        int n = points.size();

        // Loop through all possible triplets (i, j, k)
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    // Shoelace formula for area of triangle
                    // Area = 1/2 * | (x2-x1)(y3-y1) - (y2-y1)(x3-x1) | (used in this question)
                    // Area = 1/2 * | x1(y2-y3) + x2(y3-y1) + x3(y1-y2)|
                    double curr = 0.5 * fabs(
                        (points[j][0] - points[i][0]) * (points[k][1] - points[i][1]) -
                        (points[j][1] - points[i][1]) * (points[k][0] - points[i][0])
                    );
                    area = max(area, curr);
                }
            }
        }

        return area;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> points = {{0,0}, {0,1}, {1,0}, {0,2}, {2,0}};
    
    double result = sol.largestTriangleArea(points);
    cout << fixed << setprecision(2);
    cout << "Largest Triangle Area: " << result << endl;

    return 0;
}

/*
Example Output:
Largest Triangle Area: 2.00

Explanation:
Points (0,0), (0,2), (2,0) form the triangle with max area = 2.

-----------------------
Time Complexity:
- O(n^3) since we check all triplets of points.
  (n choose 3) = O(n^3)

Space Complexity:
- O(1) extra space.
*/