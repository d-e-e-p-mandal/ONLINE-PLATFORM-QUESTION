#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;                      // Input string like "3+2+1"

    vector<int> nums;              // Store extracted numbers

    // Extract numbers from the string (ignore '+')
    for (char c : s) {
        if (c != '+') {
            nums.push_back(c - '0'); // Convert char digit to int
        }
    }

    // Sort numbers in ascending order
    sort(nums.begin(), nums.end());

    // Print numbers in required format with '+'
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i != nums.size() - 1) {
            cout << "+";
        }
    }

    return 0;
}

/*
Time Complexity:
- O(n log n), where n is the number of digits in the string.
- Sorting dominates the time complexity.

Space Complexity:
- O(n), to store the extracted numbers in the vector.
*/