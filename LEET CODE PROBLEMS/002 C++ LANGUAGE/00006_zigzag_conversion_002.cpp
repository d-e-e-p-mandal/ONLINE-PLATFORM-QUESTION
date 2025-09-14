// LeetCode : 6 : ZigZag Conversion : Optimal Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        // Edge case: if only 1 row, return original string
        if(numRows == 1) return s;

        string ans = "";
        int n = s.length(); 

        // Traverse each row
        for(int i = 0; i < numRows; i++) {
            if(i == 0 || i == numRows - 1) {
                // First and last rows -> step is always 2*(numRows-1)
                for(int j = i; j < n; j += 2 * (numRows - 1)) {
                    ans += s[j];
                }
            } 
            else {
                // Middle rows -> alternate between two jumps
                bool flag = true;
                int j = i;
                while(j < n) {
                    ans += s[j];
                    if(flag) {
                        // First jump
                        j += 2 * (numRows - 1) - 2 * i;
                        flag = false;
                    } else {
                        // Second jump
                        j += 2 * (numRows - 1) - 2 * (numRows - 1 - i);
                        flag = true;
                    }
                }
            }
        }
        return ans;
    }
};

// Driver function (main)
int main() {
    Solution sol;
    string s = "PAYPALISHIRING";
    int numRows = 3;

    // Expected Output: "PAHNAPLSIIGYIR"
    cout << sol.convert(s, numRows) << endl;

    return 0;
}

/*
Time Complexity:
---------------
O(n), where n = length of the string.
Each character is processed exactly once.

Space Complexity:
----------------
O(n), for storing the result string (excluding input storage).
*/