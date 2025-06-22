//Leetcode : 85 : Maximal Rectangle
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestHistogram(vector<int>& arr){//Largest rectangle found for each row
        int len = arr.size();
        int area = 0;
        int mArea = 0;
        stack<int>st;
        for(int i =0; i<=len ; i++){ //when it end take 0 and calculate which is remaining
            int currHeight = (i==len) ? 0 : arr[i];
            while(!st.empty() && currHeight < arr[st.top()]){ //calculate height when  previous height is greater than current height
                int height = arr[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                mArea = max (mArea, height * width);
            }
            st.push(i);
        }

        return mArea;

    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int maxArea = 0;

        vector<vector<int>>arr(row,vector<int>(col,0)); //int 2d array for calculate height

        for(int i=0; i< col; i++) {
            int sum = 0;
            for(int j = 0 ; j < row ; j++){
                if(matrix[j][i] == '0')sum = 0; //if any zero then height will be reset to zero
                sum += matrix[j][i] - 48;
                arr[j][i] = sum;
            }
        }

        for(int i=0; i < row ; i++){
            maxArea = max(maxArea,largestHistogram(arr[i]));//maxArea = max(maxArea,largestHistogram(*(arr.begin() + i))); //sending each row and calculate max height
        }
        return maxArea;
    }
};

int main() {
    Solution sol;

    // Sample input
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    // Calling the maximalRectangle function
    int result = sol.maximalRectangle(matrix);

    // Output result
    cout << "Maximum rectangle area of 1s is: " << result << endl;

    return 0;
}

/*OUTPUT : Maximum rectangle area of 1s is: 6 */
/*Time Complexity : O(row * col)
Space Complexity : O(row * col)*/