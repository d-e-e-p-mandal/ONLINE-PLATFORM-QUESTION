// Leetcode : 1312 : Minimum Insertion Steps to Make a String Palindrome : Dynamic Programming (Memoization)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    // Longest Common Subsequence
    int LCS(string& s1, string& s2, int i, int j, vector<vector<int>> &dp) {
        if(i==0 || j == 0) return 0; // base case : managing out index : index shifted -1 -> 0
        // dp
        if(dp[i][j] != -1) return dp[i][j];
        // if both characters match
        if(s1[i-1] == s2[j-1]) return dp[i][j] = 1 + LCS(s1, s2, i-1, j-1, dp);
        // if not match, take max of both cases
        return dp[i][j] = max(LCS(s1, s2, i-1, j, dp), LCS(s1, s2, i, j-1, dp));
    }
public:
    int minInsertions(string s) {
        /*  Example:  
            s1 = mbadm  
            s2 = mdabm (reverse it)  
            ans = n - Longest Common Subsequence(s1, s2)
        */
        string revS = s;  // make a copy
        reverse(revS.begin(), revS.end());

        int n = s.length(); // length
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1)); // dp table
        // answer
        return n - LCS(s, revS, n, n, dp);
    }
};

int main() {
    Solution sol;
    string s;
    cout << "Enter string: ";
    cin >> s;

    int result = sol.minInsertions(s);
    cout << "Minimum insertions to make \"" << s << "\" a palindrome = " << result << endl;

    return 0;
}


/* OUTPUT :
Enter string: mbadm
Minimum insertions to make "mbadm" a palindrome = 2
*/

/*Time Complexity: O(n^2) (each (i, j) state computed once).
Space Complexity: O(n^2) + O(n) (DP table + recursion stack). */