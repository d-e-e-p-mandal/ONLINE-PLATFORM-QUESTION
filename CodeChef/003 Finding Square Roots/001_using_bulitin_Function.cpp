#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;                     // Number of test cases

    while (T--) {
        int N;
        cin >> N;                 // Input number

        int ans = (int)sqrt(N);   // Floor value of square root of N
        cout << ans << "\n";      // Output result
    }

    return 0;
}

/*
Time Complexity:
- O(T), where T is the number of test cases.
- Each sqrt operation runs in constant time O(1).

Space Complexity:
- O(1), constant extra space used.
*/