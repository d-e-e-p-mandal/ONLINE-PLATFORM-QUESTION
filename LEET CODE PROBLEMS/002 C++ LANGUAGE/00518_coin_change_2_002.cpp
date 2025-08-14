// LeetCode : 518 : Coin Change 2 : Dynamic Porgramming : Memoization 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalCombination(int amount, vector<int>& coins, int ind, vector<vector<int>>& dp){
        if(ind == 0) { // base case : at index 0 check coins[0] is possible or not
            if(amount % coins[0] == 0) return 1; // true
            return 0;
        }

        // dp
        if(dp[ind][amount] != -1) return dp[ind][amount];

        int notPick = totalCombination(amount, coins, ind-1, dp); // not take index coin

        int pick = 0;
        if(coins[ind] <= amount) pick = totalCombination(amount-coins[ind], coins, ind, dp); // same index

        return dp[ind][amount] = notPick + pick; // total possibility
    }
public:
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1)); // ds

        return totalCombination(amount, coins, n-1, dp);
    }
};

int main() {
    int amount, n;
    cout << "Enter amount: ";
    cin >> amount;

    cout << "Enter number of coins: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter coin denominations: ";
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    Solution sol;
    int result = sol.change(amount, coins);
    cout << "Number of combinations: " << result << endl;

    return 0;
}

/*OUTPUT :
Enter amount: 5
Enter number of coins: 3
Enter coin denominations: 1 2 5
Number of combinations: 4 */

/*Time Complexity: O(n * amount), Space Complexity: O(n * amount + n)*/