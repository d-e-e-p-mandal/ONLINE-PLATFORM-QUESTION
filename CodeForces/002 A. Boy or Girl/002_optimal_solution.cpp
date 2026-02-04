#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;                  // Read the input string

    int mask = 0;              // Bitmask to track distinct characters

    for (char c : s) {
        int bit = c - 'a';     // Map character 'a'–'z' to bits 0–25
        mask |= (1 << bit);    // Set the corresponding bit
    }

    int distinct = __builtin_popcount(mask); // Count number of set bits (distinct characters)

    if (distinct % 2 == 0)
        cout << "CHAT WITH HER!";  // Even number of distinct characters
    else
        cout << "IGNORE HIM!";     // Odd number of distinct characters

    return 0;
}

/*
Time Complexity:
- O(n), where n is the length of the string.
- Each character is processed once.

Space Complexity:
- O(1), because only a single integer (bitmask) is used.
- Independent of input size (constant extra space).
*/