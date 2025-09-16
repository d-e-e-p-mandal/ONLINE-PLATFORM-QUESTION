#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int count = 0;

        // Store broken letters in a set for quick lookup
        unordered_set<char> s;
        for (int i = 0; i < brokenLetters.length(); i++) {
            s.insert(brokenLetters[i]);
        }

        bool flag = true; // true means current word can be typed
        for (int i = 0; i < text.length(); i++) {
            if (text[i] == ' ') {
                // If current word is typeable, increase count
                if (flag == true) count++;
                else flag = true; // reset flag for next word
            }

            // If current character is a broken letter, mark word as not typeable
            if (s.count(text[i])) { // s.contains(text[i])
                flag = false;
            }
        }

        // After the loop, check for last word
        if (flag == true) count++;

        return count;
    }
};

int main() {
    Solution sol;
    string text = "hello world code";
    string broken = "ad";

    int result = sol.canBeTypedWords(text, broken);
    cout << "Number of words that can be typed: " << result << endl;

    return 0;
}

/*
Output:
Number of words that can be typed: 1

Explanation:
- "hello" -> ok
- "world" -> ok
- "code" -> contains 'd' (broken), cannot be typed
=> total = 2 words (if broken="ad"), 
But here "a" and "d" both block, so result = 2 not 1.
*/

// ----------------------
// Time Complexity:
// O(n + m), where n = length of text, m = length of brokenLetters
// - Inserting brokenLetters into set: O(m)
// - Scanning text once: O(n)
// Overall: O(n + m)

// Space Complexity:
// O(m) for storing brokenLetters in unordered_set
// ----------------------
