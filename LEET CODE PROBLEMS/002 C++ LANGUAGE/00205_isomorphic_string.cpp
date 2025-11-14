// LeetCode : 205 : Isomorphic String

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to check if two strings are isomorphic
    bool isIsomorphic(string s, string t) {
        int n = s.length();

        unordered_map<char, char> mp1; // map from s → t
        unordered_map<char, char> mp2; // map from t → s

        for (int i = 0; i < n; i++) {

            // Check forward mapping (s → t)
            if (mp1.count(s[i])) {
                if (mp1[s[i]] != t[i]) return false;
            } else {
                mp1[s[i]] = t[i];
            }

            // Check backward mapping (t → s)
            if (mp2.count(t[i])) {
                if (mp2[t[i]] != s[i]) return false;
            } else {
                mp2[t[i]] = s[i];
            }
        }

        return true; // Strings are isomorphic
    }
};

// -----------------------
// Main Function Example
// -----------------------
int main() {
    Solution sol;

    string s = "egg";
    string t = "add";

    bool result = sol.isIsomorphic(s, t);

    cout << (result ? "Isomorphic" : "Not Isomorphic") << endl;

    return 0;
}

/*
-------------------------------------------
Example Output:
-------------------------------------------
Isomorphic

-------------------------------------------
Explanation:
-------------------------------------------
egg  → add
e → a
g → d

All characters map consistently in both directions.

-------------------------------------------
Time Complexity: O(n)
    - Traverse both strings once.
    - Map lookups O(1) average for unordered_map.

Space Complexity: O(1)
    - At most 256 character mappings.
-------------------------------------------
*/