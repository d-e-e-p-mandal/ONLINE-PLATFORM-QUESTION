// LeetCode :  Egg Drop With 2 Eggs and N Floors : Dynamic Programming 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // dp[eggs][floors] stores the minimum moves required
    map<pair<int,int>, int> memo;

    int solve(int eggs, int floors) {
        // Base cases
        if (floors == 0 || floors == 1) return floors;   // 0 or 1 floor needs that many trials
        if (eggs == 1) return floors;                   // If only 1 egg left, must check all floors

        // Check memo
        if (memo[{eggs, floors}]) return memo[{eggs, floors}];

        int ans = INT_MAX;

        // Try dropping from each floor i
        for (int i = 1; i <= floors; i++) {
            int breakCase = solve(eggs - 1, i - 1);   // Egg breaks -> search below
            int notBreakCase = solve(eggs, floors - i); // Egg survives -> search above

            int worst = 1 + max(breakCase, notBreakCase);
            ans = min(ans, worst);
        }

        return memo[{eggs, floors}] = ans;
    }

    int twoEggDrop(int n) {
        return solve(2, n); // We always start with 2 eggs and n floors
    }
};

int main() {
    Solution sol;

    int n1 = 10;
    cout << "For n = " << n1 << " floors -> Min moves = "
         << sol.twoEggDrop(n1) << endl;

    int n2 = 36;
    cout << "For n = " << n2 << " floors -> Min moves = "
         << sol.twoEggDrop(n2) << endl;

    int n3 = 100;
    cout << "For n = " << n3 << " floors -> Min moves = "
         << sol.twoEggDrop(n3) << endl;

    return 0;
}

/*
⚡ Complexity Analysis:

Time Complexity: O(n^2) with plain recursion, but with memoization ~ O(n^2).
 - For each floor we try dropping, so O(floors) per state.
 - States = eggs * floors = O(2n).
 - So worst O(n^2).

Space Complexity: O(n) recursion depth + memo storage.
*/