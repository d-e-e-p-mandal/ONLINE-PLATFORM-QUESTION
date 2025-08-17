// Leetcode : 1143 : Longest Common Subsequence : Dynamic Programming (Tabulation)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int m = text1.length(); // length of text1
        int n = text2.length(); // length of text2

        vector<vector<int>> dp(m+1, vector<int>(n+1,0)); //dp

        // base case : -1 index shifter to index 0 : -1 index length 0, we alreday take all element is 0 so we don't need to write base case

        for(int i = 1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1]; // if both element are same
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
            }
        }

        return dp[m][n];
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
Space Complexity: O(m * n)
*/