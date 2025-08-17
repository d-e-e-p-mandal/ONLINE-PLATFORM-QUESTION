// Leetcode : 1143 : Longest Common Subsequence : Dynamic Programming (Memoization)
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int longest(string &text1, string &text2, int i, int j, vector<vector<int>>& dp) {
        // base case : index 0 means -> index -1 : (for handle -ve index it shoift 0 by shifting +1)
        if(i == 0 || j == 0) return 0; 
        //dp
        if(dp[i][j] != -1) return dp[i][j];
        // if both element same : check index (ind -1)
        if(text1[i-1] == text2[j-1]) return dp[i][j] = 1 + longest(text1, text2, i-1, j-1, dp);
        // if element are different : move max of sloution of all cases
        return dp[i][j] = max(longest(text1, text2, i-1, j, dp), longest(text1, text2, i, j-1, dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int i = text1.length(); // length of text1
        int j = text2.length(); // length of text2

        vector<vector<int>> dp(i+1, vector<int>(j+1,-1)); //dp

        return longest(text1, text2, i, j, dp);
    }
};

int main() {
    Solution sol;
    
    string text1, text2;
    cout << "Enter first string: ";
    cin >> text1;
    cout << "Enter second string: ";
    cin >> text2;

    int ans = sol.longestCommonSubsequence(text1, text2);
    cout << "Length of Longest Common Subsequence: " << ans << endl;

    return 0;
}

/*
Enter first string: abcde
Enter second string: ace
Length of Longest Common Subsequence: 3
*/

/*
Time Complexity: O(n × m)
Space Complexity: O(n × m) + O(n + m) (DP table + recursion stack)
*/