// LeetCode : 22 : Generate Parentheses : (DP Solution)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // dp[i] stores all valid parentheses combinations of length 2*i
        vector<vector<string>> dp(n+1);

        // Base case: for n=0, only the empty string is valid
        dp[0].push_back("");

        // Build solutions from smaller subproblems
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                // Split into two parts:
                // "(" + inside (from dp[j]) + ")" + outside (from dp[i-1-j])
                for (string inside : dp[j]) {
                    for (string outside : dp[i-1-j]) {
                        dp[i].push_back("(" + inside + ")" + outside);
                    }
                }
            }
        }

        return dp[n];
    }
};

int main() {
    Solution sol;
    int n = 3;

    vector<string> result = sol.generateParenthesis(n);

    cout << "Valid Parentheses Combinations for n=" << n << ":\n";
    for (auto &s : result) {
        cout << s << "\n";
    }

    return 0;
}

/*
Example Output for n=3:
((()))
(()())
(())()
()(())
()()()

-----------------------
Time Complexity:
- The number of results is Catalan(n).
- Generating all results requires O(Catalan(n) * n) work.
- The DP loops add polynomial overhead, but asymptotically still O(Catalan(n) * n).

Space Complexity:
- dp stores all intermediate combinations.
- Size of dp[i] = Catalan(i), each string length = 2*i.
=> Total space = O(Catalan(n) * n)
*/