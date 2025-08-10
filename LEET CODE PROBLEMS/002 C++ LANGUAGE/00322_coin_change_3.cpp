// Leetcode : 322 : Coin Change : Dynamic Programming (Tabulation) : Space Optimized
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // initially all cell fill with a large number
        vector<int> prev(amount+1, 1e9), curr(amount+1);

        //base case : 1st row filled that cell which amount directly divisble by coins[0]
        for(int j=0; j<=amount; j++){
            if(j % coins[0] == 0) prev[j] = j / coins[0];
        }


        for(int i=1; i<n; i++){
            for(int j=0; j<=amount; j++){
                // skip index : copy previous row
                int notPick =  0 + prev[j];
                // pick elemet : add 1 coin if possible
                int pick = 1e9;
                // use 1 + curr because same index repeated
                if(coins[i] <= j) pick = 1 + curr[j-coins[i]];
                // store minimum
                curr[j] = min(notPick, pick);
            }
            prev = curr;
        }

        return (prev[amount] >= 1e9) ? -1 : prev[amount];
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
Space Complexity: O(amount)*/