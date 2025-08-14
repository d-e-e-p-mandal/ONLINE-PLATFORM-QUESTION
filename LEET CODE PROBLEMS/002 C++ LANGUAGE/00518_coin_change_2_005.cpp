// LeetCode : 518 : Coin Change 2 : Dynamic Porgramming : Tabulation 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size(); 
        vector<long>prev(amount+1, 0),curr(amount+1); // data structure

        // base case :
        prev[0] = 1; // if amout is 0 in index 0 then it is true

        for(int i=1; i<=n; i++) { // index taking as +1 for handle ostside -1 index
            for(int j=0; j<= amount; j++) {  // amount
                int notPick = prev[j]; // notPick

                int pick = 0; 
                if(coins[i-1] <= j) pick = curr[j-coins[i-1]]; // pick : coins inde 0 to n-1 : take form curr because take form same index

                curr[j] = (long) notPick + pick; // total ways
            }
            prev = curr;
        }

        return prev[amount]; // ans store asked amount cell
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