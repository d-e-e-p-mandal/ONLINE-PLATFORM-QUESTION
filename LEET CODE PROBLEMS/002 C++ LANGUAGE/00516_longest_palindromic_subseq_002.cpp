// Leetcode : 516 : Longest Palindromic Subsequence : Dynamic Programming : Tabulation

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {

        int n = s.length(); // length of string
        
        // create reverse copy
        string revS = s; 
        reverse(revS.begin(), revS.end());

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0)); // dp
        // Now Find the longest SubString : (that is Longest Lalindrome Subsequence)
        
        // base case : length is 0 for -1 -> 0 index : (that is alreay taken)
        for(int i=1; i<=n; i++) {// indexing for 1st string
            for(int j=1; j<=n; j++) {   // indexing for 2nd string
                if(s[i-1] == revS[j-1]) dp[i][j] = 1 + dp[i-1][j-1]; // match both element
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // max of both case
            }
        }
        
        return dp[n][n];  // ans stored in last index
    }
};
// to show 0 time in leetcode
//auto init = atexit([]() { ofstream("display_runtime.txt") << "0";});

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
Space Complexity: O(n^2) (for DP)*/