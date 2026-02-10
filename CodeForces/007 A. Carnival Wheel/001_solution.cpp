#include <bits/stdc++.h>
using namespace std;

void solve() {
    int l, a, b;
    cin >> l >> a >> b;          // Read inputs

    int g = gcd(l, b);           // Compute gcd of l and b

    // Compute the maximum value ≤ (l - 1) that is congruent to a (mod g)
    int ans = a + (((l - 1 - a) / g) * g);

    cout << ans << '\n';         // Output the result
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr); 

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;                    // Number of test cases
    while (t--) {
        solve();
    }
}

/*
Time Complexity:
- For each test case: O(log(min(l, b))) due to gcd computation.
- Overall: O(t · log(min(l, b))).

Space Complexity:
- O(1), constant extra space.
*/