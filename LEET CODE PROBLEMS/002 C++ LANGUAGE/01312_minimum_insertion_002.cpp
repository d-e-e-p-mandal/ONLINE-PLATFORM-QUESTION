// Leetcode : 1312 : Minimum Insertion Steps to Make a String Palindrome : Dynamic Programming (Tabulation)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        
        /*  s1 = mbadm : 
            s2 = mbadm // reverse it
            ans = n - Longeset Common SubSequence s1 & s2
        */
        string revS = s;  // make a copy
        reverse(revS.begin(), revS.end());

        int n = s.length(); // length
        vector<vector<int>> dp(n+1,vector<int>(n+1, 0)); // dp : datastructure

        // base case : out side form it index -1 shited to 0 : 0 (row 0) fill with 0 : that already taken
 
        for(int i=1; i<=n; i++) {   // row
            for(int j=1; j<=n; j++) {   // col
                if(s[i-1] == revS[j-1]) dp[i][j] = 1 + dp[i-1][j-1]; // if match both element form s1 and revS
                else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);   // if not match take max form previous
            }
        }

        // ans
        return n - dp[n][n];
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
Space Complexity: O(n^2) (DP table). */