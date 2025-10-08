// LeetCode : 22 : Generate Parentheses : (Recursion Solution)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Recursive helper function to build valid parentheses strings
    void generate(int n, int i, int j, string s, vector<string>& ans) {
        // Base case: if the string has 2*n characters, add to result
        if (s.size() == n * 2) {
            ans.push_back(s);
            return;
        }

        // If we can still place an '(', add it
        if (i < n) 
            generate(n, i+1, j, s+"(", ans);

        // If we can place a ')', i.e., there are unmatched '('
        if (j < i) 
            generate(n, i, j+1, s+")", ans);
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(n, 0, 0, "", ans);
        return ans;
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
- There are Catalan(n) valid sequences (≈ 4^n / (n^(3/2) * sqrt(pi))).
- Each sequence has length 2n.
=> O(Catalan(n) * n)

Space Complexity:
- Recursion depth: O(2n) in worst case.
- Result storage: O(Catalan(n) * n).
=> O(Catalan(n) * n)
*/