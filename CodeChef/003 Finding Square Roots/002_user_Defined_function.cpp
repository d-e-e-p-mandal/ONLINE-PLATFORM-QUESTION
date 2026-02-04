#include <bits/stdc++.h>
using namespace std;

// Function to compute floor(sqrt(n)) using binary search
int mySqrt(int n) {
    int low = 0, high = n, ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2; // Prevent overflow

        if (mid * mid <= n) {
            ans = mid;      // mid is a valid candidate
            low = mid + 1; // try to find a larger value
        } else {
            high = mid - 1; // reduce search space
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;                  // Number of test cases

    while (T--) {
        int N;
        cin >> N;              // Input number
        cout << mySqrt(N) << "\n"; // Output floor of sqrt(N)
    }

    return 0;
}

/*
Time Complexity:
- For each test case: O(log N), due to binary search.
- Overall: O(T log N), where T is the number of test cases.

Space Complexity:
- O(1), constant extra space.
*/