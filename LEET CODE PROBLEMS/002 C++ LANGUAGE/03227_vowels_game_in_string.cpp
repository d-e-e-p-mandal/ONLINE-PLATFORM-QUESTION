// LeeCode : 3227 : Vowels Game in a String
#include <bits/stdc++.h>
using namespace std;

class Solution {
    // Helper function: checks if the string contains any vowel
    bool isAnyVowel(string& s) {
        int n = s.length();
        for(int i = 0; i < n; i++) {
            // Check for lowercase vowels
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                return true;
        }
        return false;
    }
public:
    // Main function: returns true if Alice wins (string has a vowel), false otherwise
    bool doesAliceWin(string s) {
        return isAnyVowel(s);
    }
};

// Driver function (main)
int main() {
    Solution sol;

    string s1 = "hello";
    string s2 = "rhythm";   // no vowel

    cout << (sol.doesAliceWin(s1) ? "Alice Wins" : "Alice Loses") << endl; // Expected: Alice Wins
    cout << (sol.doesAliceWin(s2) ? "Alice Wins" : "Alice Loses") << endl; // Expected: Alice Loses

    return 0;
}

/*
Time Complexity:
---------------
O(n), where n = length of the string.
We scan each character at most once.

Space Complexity:
----------------
O(1), constant extra space (only a few variables).
*/