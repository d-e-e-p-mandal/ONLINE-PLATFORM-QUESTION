// Leetcode : 516 :Longest Palindromic Subsequence : Dynamic Programming : Memoization

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int LCS(string& s1, string& s2, int i, int j, vector<vector<int>> &dp) {
        // base case : -1 index shifted to 0 index : LCS 0 when -1 index
        if(i == 0 || j == 0) return 0;
        // dp
        if(dp[i][j] != -1) return dp[i][j];
        // if both index is same
        if(s1[i-1] == s2[j-1]) return dp[i][j] = 1 + LCS(s1, s2, i-1, j-1, dp);
        // find max of both case
        return dp[i][j] = max(LCS(s1, s2, i-1, j, dp), LCS(s1, s2, i, j-1, dp));
    }
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length(); // length of string
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1)); // dp
        // create reverse copy
        string revS = s; 
        reverse(revS.begin(), revS.end());
        // Now Find the longest SubSequence : (that is Longest Palindrome Subsequence)
        return LCS(s, revS, n, n, dp);
    }
};

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    Solution sol;
    int result = sol.longestPalindromeSubseq(s);
    cout << "Length of Longest Palindromic Subsequence: " << result << endl;

    return 0;
}

/*OUTPUT :
Enter string: bbbab
Length of Longest Palindromic Subsequence: 4
*/

/*Time Complexity: O(n^2)
Space Complexity: O(n^2) (for DP) + O(n) (recursion stack) */