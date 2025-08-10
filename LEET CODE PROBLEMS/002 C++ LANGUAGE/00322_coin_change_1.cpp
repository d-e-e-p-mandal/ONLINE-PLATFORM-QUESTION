// Leetcode : 322 : Coin Change : Dynamic Programming (Memoization)
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minCoin(vector<int>& coins, int amount, int ind, vector<vector<int>>& dp) {
        if(ind == 0){
            if(amount % coins[ind] == 0) return dp[ind][amount] =  amount/coins[ind]; // if amount is divisible by any number it refers amount = k * number
            return dp[ind][amount] = 1e9; // 0 <= amount <= 1e4 : so we can tak max number 1e9 or INT_MAX 
        }
        //dp
        if(dp[ind][amount] != -1) return dp[ind][amount];
        //skip index
        int notPick = 0 + minCoin(coins, amount, ind-1, dp);
        // pick element and use same index for all possibility because k * conins[ind] < amount
        int pick = INT_MAX;
        if(coins[ind] <= amount) pick = 1 + minCoin(coins, amount-coins[ind], ind, dp);
        // store minimum
        return dp[ind][amount] = min(notPick, pick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1)); // datastructure

        int ans = minCoin(coins, amount, n-1, dp);

        return (ans >= 1e9) ? -1 : ans;
    }
};

int main() {
    Solution sol;
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int result = sol.coinChange(coins, amount);
    cout << "Minimum coins required: " << result << endl;

    return 0;
}

/*OUTPUT : Minimum coins required: 3*/
/*Time Complexity: O(n * amount)
Space Complexity: O(n * amount) + O(amount) (DP table + recursion stack)*/