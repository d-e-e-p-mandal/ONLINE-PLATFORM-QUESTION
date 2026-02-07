#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n), ans(n);

    // Read the permutation and build its inverse
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        ans[arr[i] - 1] = i + 1;   // inverse mapping
    }

    // Print the inverse permutation
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
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
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

/*
-----------------------------------------
Sample Input:
5
2 3 4 5 1

Sample Output:
5 1 2 3 4

Explanation:
Given permutation:
Index: 1 2 3 4 5
Value: 2 3 4 5 1

Inverse permutation:
1 is at position 5
2 is at position 1
3 is at position 2
4 is at position 3
5 is at position 4

-----------------------------------------
Time Complexity:
O(n)
Reason:
Single pass to build inverse permutation and one pass to print.

Space Complexity:
O(n)
Reason:
Extra array used to store the inverse permutation.

-----------------------------------------
*/