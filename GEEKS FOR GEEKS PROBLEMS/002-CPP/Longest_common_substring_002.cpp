// GFG : Longest Common SubStrig : Dynamic Programming (Tabulation : Bottom-Up) : Space Optimized
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubstr(string& s1, string& s2) {
        int m = s1.length(), n = s2.length();
        vector<int>prev(n+1, 0), curr(n+1);
        
        int ans = 0;
        
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(s1[i-1] == s2[j-1]) {
                    curr[j] = 1 + prev[j-1];  // extend substring
                    ans = max(ans, curr[j]);
                } else {
                    curr[j] = 0; // reset (substring must be contiguous)
                }
            }
            prev = curr;
        }
        
        return ans;
    }
};

int main() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    Solution sol;
    int result = sol.longestCommonSubstr(s1, s2);
    cout << "Length of Longest Common Substring: " << result << endl;

    return 0;
}

/*OUPUT :
Enter first string: abcde
Enter second string: abfce
Length of Longest Common Substring: 2
*/

/*Time Complexity: O(m * n)
Space Complexity: O(2 * n)*/