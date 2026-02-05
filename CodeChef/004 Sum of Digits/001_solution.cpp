#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;                    // Number of test cases

    while (T--) {
        int N;
        cin >> N;                // Input number

        int sum = 0;             // Stores sum of digits
        while (N > 0) {
            sum += N % 10;       // Add last digit
            N /= 10;             // Remove last digit
        }

        cout << sum << "\n";     // Output sum of digits
    }

    return 0;
}

/*
Time Complexity:
- For each test case: O(d), where d is the number of digits in N.
- Overall: O(T × d).

Space Complexity:
- O(1), constant extra space.
*/