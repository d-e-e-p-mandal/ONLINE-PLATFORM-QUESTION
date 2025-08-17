// Leetcode : 1143 : Longest Common Subsequence : Dynamic Programming (Memoization)
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int longest(string &text1, string &text2, int i, int j, vector<vector<int>>& dp) {
        // base case : (i and j) < 0 
        if(i == -1 || j == -1) return 0; 
        //dp
        if(dp[i][j] != -1) return dp[i][j];
        // if both element same 
        if(text1[i] == text2[j]) return dp[i][j] = 1 + longest(text1, text2, i-1, j-1, dp);
        // if element are different 
        return dp[i][j] = max(longest(text1, text2, i-1, j, dp), longest(text1, text2, i, j-1, dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int i = text1.length(); // length of text1
        int j = text2.length(); // length of text2

        vector<vector<int>> dp(i, vector<int>(j,-1)); //dp

        return longest(text1, text2, i-1, j-1, dp);
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