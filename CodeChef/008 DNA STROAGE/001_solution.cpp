#include <bits/stdc++.h>
using namespace std;

void solve(int n, string& s) {
    string ans = "";               // Store encoded DNA sequence

    for (int i = 0; i < n; i = i + 2) {
        string temp = "";
        temp += s[i];              // First bit
        temp += s[i + 1];          // Second bit
        
        // Mapping according to given rules
        if (temp == "00") ans += "A";
        else if (temp == "01") ans += "T";
        else if (temp == "10") ans += "C"; 
        else ans += "G";
    }
        
    cout << ans << "\n";           // Output encoded string
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;                      // Number of test cases

    while (t--) {
        int n;
        cin >> n;                  // Length of binary string (even)
        string s;
        cin >> s;                  // Binary string

        solve(n, s);
    }
}

/*
Time Complexity:
- For each test case: O(n)
- Overall: O(sum of n) ≤ 1000

Space Complexity:
- O(n), for storing the resulting encoded string.
*/