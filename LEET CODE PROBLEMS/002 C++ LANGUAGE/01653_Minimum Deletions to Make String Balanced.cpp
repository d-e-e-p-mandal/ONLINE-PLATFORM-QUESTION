// LeetCode : 1653. Minimum Deletions to Make String Balanced

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();

        int a = 0, b = 0;
        int mini = INT_MAX;

        // Count total number of 'a'
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') a++;
        }

        // Traverse string and calculate minimum deletions
        for (int i = 0; i < n; i++) {

            if (s[i] == 'a')
                a--;   // this 'a' moves to left side

            // deletions needed = remaining 'a' on right + 'b' on left
            mini = min(mini, a + b);

            if (s[i] == 'b')
                b++;   // count 'b' on left side
        }

        return mini;
    }
};

int main() {
    string s;
    cin >> s;

    Solution obj;
    cout << obj.minimumDeletions(s) << endl;

    return 0;
}

/*
-----------------------------------------
Sample Input:
aababbab

Sample Output:
2

Explanation:
Minimum deletions required to make all 'a' appear before all 'b' is 2.

-----------------------------------------
Time Complexity:
O(n)
Reason:
Two linear passes over the string.

Space Complexity:
O(1)
Reason:
Only constant extra variables used.

-----------------------------------------
*/