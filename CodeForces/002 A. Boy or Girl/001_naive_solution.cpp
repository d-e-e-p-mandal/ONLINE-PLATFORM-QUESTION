#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;                     // Read input string

    int mask = 0;                   // (Unused) variable, does not affect logic
    unordered_set<char> s;          // Set to store distinct characters

    for (char c : str) {
        s.insert(c);                // Insert each character into the set
    }

    int distinct = s.size();        // Number of distinct characters

    if (distinct % 2 == 0)
        cout << "CHAT WITH HER!";   // Even number of distinct characters
    else
        cout << "IGNORE HIM!";      // Odd number of distinct characters

    return 0;
}

/*
Time Complexity:
- O(n) on average, where n is the length of the string.
- Each insertion into unordered_set takes O(1) average time.

Space Complexity:
- O(k), where k is the number of distinct characters.
- In the worst case (all characters unique), k ≤ 26 for lowercase English letters.
*/