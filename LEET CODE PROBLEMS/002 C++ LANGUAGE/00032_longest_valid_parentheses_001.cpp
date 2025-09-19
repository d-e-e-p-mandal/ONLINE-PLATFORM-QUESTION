// LeetCode : 32 : Longest Valid Parentheses : Stack Solution
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the length of the longest valid parentheses substring
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); // Base index to handle edge cases

        int maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            // If we find a matching pair
            if (st.top() != -1 && s[st.top()] == '(' && s[i] == ')') {
                st.pop(); // Pop the matching '('
                maxLen = max(maxLen, i - st.top()); // Update length
            } 
            else {
                // Push current index if no match
                st.push(i);
            }
        }
        return maxLen;
    }
};

int main() {
    Solution sol;
    
    // Example test cases
    string s1 = "(()";
    cout << "Input: " << s1 << "\n";
    cout << "Longest Valid Parentheses Length: " 
         << sol.longestValidParentheses(s1) << "\n\n";

    string s2 = ")()())";
    cout << "Input: " << s2 << "\n";
    cout << "Longest Valid Parentheses Length: " 
         << sol.longestValidParentheses(s2) << "\n\n";

    string s3 = "";
    cout << "Input: \"" << s3 << "\"\n";
    cout << "Longest Valid Parentheses Length: " 
         << sol.longestValidParentheses(s3) << "\n\n";

    string s4 = "()(())";
    cout << "Input: " << s4 << "\n";
    cout << "Longest Valid Parentheses Length: " 
         << sol.longestValidParentheses(s4) << "\n";

    return 0;
}

/*
Time Complexity: O(n)
 - We traverse the string once and perform stack operations in O(1).
 - So total = O(n), where n = length of string.

Space Complexity: O(n)
 - In the worst case, all indices are pushed into the stack.
 - So auxiliary stack space = O(n).
*/