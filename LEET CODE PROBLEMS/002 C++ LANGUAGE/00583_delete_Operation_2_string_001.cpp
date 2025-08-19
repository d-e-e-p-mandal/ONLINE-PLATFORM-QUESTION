// LeetCode : 583 : Delete Operation for Two Strings : Dynamic Programming : Memoization
// Take U ForWord : Minimum insertions or deletions to convert string A to B

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int LCS(string& s1, string& s2, int i, int j, vector<vector<int>> &dp) {
        // base case : index -1 shifted to 0 to handle -ve index length 0 when it out of index
        if(i == 0 || j == 0) return 0;
        // dp
        if(dp[i][j] != -1) return dp[i][j];
        // if both element same
        if(s1[i-1] == s2[j-1]) return dp[i][j] = 1 + LCS(s1, s2, i-1, j-1, dp);
        // max of both
        return dp[i][j] = max(LCS(s1, s2, i-1, j, dp), LCS(s1, s2, i, j-1, dp));
    }

public:
    int minDistance(string word1, string word2) {
        int m = word1.length(); // length of word1
        int n = word2.length(); // length of word2
        // dp
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        // ans : m + n - 2 * LCS (longest common subsequence)
        return m + n - 2 * LCS(word1, word2, m, n, dp);
    }
};

int main() {
    Solution sol;

    string word1 = "sea";
    string word2 = "eat";

    cout << "Minimum deletions to make \"" << word1 
         << "\" and \"" << word2 << "\" equal: " 
         << sol.minDistance(word1, word2) << endl;

    // More test cases
    cout << sol.minDistance("leetcode", "etco") << endl; // expected 4
    cout << sol.minDistance("abc", "def") << endl;       // expected 6
    cout << sol.minDistance("abc", "abc") << endl;       // expected 0

    return 0;
}

/* OUTPUT : 
Minimum deletions to make "sea" and "eat" equal: 2
4
6
0
*/

/*Time Complexity: O(m * n)
Space Complexity: O(m * n) + O(m + n) recursion stack*/