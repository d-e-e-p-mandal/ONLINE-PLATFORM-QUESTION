// LEETCODE 66 : Optimal Solution
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // Traverse from last digit
        for (int i = n - 1; i >= 0; i--) {

            // If digit is less than 9, just add 1 and return
            if (digits[i] < 9) {
                digits[i]++;
                return digits;   // return using same vector
            }

            // If digit is 9, make it 0 and continue carry
            digits[i] = 0;
        }

        // If all digits were 9, insert 1 at the beginning
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> digits(n);
    for (int i = 0; i < n; i++)
        cin >> digits[i];

    Solution obj;
    vector<int> ans = obj.plusOne(digits);

    for (int x : ans)
        cout << x << " ";

    cout << endl;
    return 0;
}

/*
-----------------------------------------
Sample Input:
3
1 2 3

Sample Output:
1 2 4

Explanation:
123 + 1 = 124

-----------------------------------------
Another Example:
Input:
3
9 9 9

Output:
1 0 0 0

-----------------------------------------
Time Complexity:
O(n)
Reason:
In worst case, all digits are 9 and we traverse the entire array once.

Space Complexity:
O(1)
Reason:
Modification is done in-place (excluding output).

-----------------------------------------
*/