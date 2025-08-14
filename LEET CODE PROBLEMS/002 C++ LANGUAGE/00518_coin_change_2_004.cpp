// LeetCode : 518 : Coin Change 2 : Dynamic Porgramming : Tabulation 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector<vector<long>> dp(n, vector<long>(amount+1, 0)); // dp

        // base case : if amount is divisible by coin[0], then it 1 possible way
        // index 0 set by default
        for(int j=0; j<=amount; j++) {  // amount
            if(j % coins[0] == 0) dp[0][j] = 1;   
        }

        for(int i =1; i<n; i++) { // index
            for(int j=0; j<= amount; j++) { // amount
                int notPick = dp[i-1][j]; // notPick so take form previous

                int pick = 0;
                if(coins[i] <= j) pick = dp[i][j-coins[i]];  // take form same index
                dp[i][j] = (long) notPick + pick; // type casting : (total ways)
            }
        }

        return dp[n-1][amount];
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

/*Time Complexity: O(n * amount), Space Complexity: O(n * amount) */