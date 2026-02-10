#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;                    // Input large number as string

    int carry = 1;               // We want to add 1 to the number
    for (int i = s.size() - 1; i >= 0; i--) {
        int digit = (s[i] - '0') + carry; // Add carry to current digit
        s[i] = (digit % 10) + '0';        // Update digit
        carry = digit / 10;               // Update carry
        if (carry == 0) break;             // Stop if no carry remains
    }

    // If carry is still left, prepend '1'
    if (carry) {
        s = '1' + s;
    }

    cout << s << '\n';           // Output result
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;                    // Number of test cases
    while (t--) {
        solve();
    }
}

/*
Time Complexity:
- For each test case: O(n), where n is the length of the string.
- In the worst case, all digits are processed (e.g., "9999").

Space Complexity:
- O(1) extra space.
- String is modified in-place (ignoring input storage).
*/