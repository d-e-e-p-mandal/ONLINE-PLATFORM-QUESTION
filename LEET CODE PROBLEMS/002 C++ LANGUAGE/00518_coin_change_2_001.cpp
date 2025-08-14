// LeetCode : 518 : Coin Change 2 : Dynamic Porgramming : Memoization 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalCombination(int amount, vector<int>& coins, int ind, vector<vector<int>>& dp){
        if(ind == -1) {  // base case : check all condition using notPick and pick when it outside of the index it hit base case
            if(amount == 0) return 1;
            return 0;
        }
        // dp 
        if(dp[ind+1][amount] != -1) return dp[ind+1][amount]; // it call funtion until index -1 so handle -1 index using +1 
        int notPick = totalCombination(amount, coins, ind-1, dp); // not take index

        int pick = 0;
        if(coins[ind] <= amount) pick = totalCombination(amount-coins[ind], coins, ind, dp); // index will not be changed

        return dp[ind+1][amount] = notPick + pick; // total combination of notPick and pick
    }
public:
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size(); 
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1)); // data structure

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