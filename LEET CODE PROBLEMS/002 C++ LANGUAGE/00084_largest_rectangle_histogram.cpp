// LEETCODE : 83 : Largest Rectangle in Histogram :(Optimal)
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm> // for max

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxA = 0;
        stack<int> st;
        int n = heights.size();
        for(int i = 0; i <= n; i++) {
            // calculate area when heights[i] is smaller than previous
            while(!st.empty() && (i == n || heights[i] < heights[st.top()])) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxA = max(maxA, height * width);
            }
            st.push(i);
        }
        return maxA;
    }
};

int main() {
    Solution sol;

    // Example histogram heights
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    // Compute and print result
    int maxArea = sol.largestRectangleArea(heights);
    cout << "Largest Rectangle Area: " << maxArea << endl;

    return 0;
}

/*Largest Rectangle Area: 10*/