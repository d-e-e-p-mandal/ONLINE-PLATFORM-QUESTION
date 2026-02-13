#include <bits/stdc++.h>
using namespace std;

// Function to check if watermelon can be divided
void solve(int n) {
  
    // Condition:
    // n must be greater than 2
    // and n must be even
    if (n > 2 && !(n & 1)) 
        cout << "YES";
    else 
        cout << "NO";
}

int main() {
    ios::sync_with_stdio(false);
  
    cin.tie(nullptr); 
    cout.tie(nullptr); 

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    // cin >> t;   // Single test case
    while (t--) {
        int n;
        cin >> n;     // Input weight
        solve(n);
    }
}

/*
Time Complexity:
- O(1), constant time check.

Space Complexity:
- O(1), constant extra space.
*/