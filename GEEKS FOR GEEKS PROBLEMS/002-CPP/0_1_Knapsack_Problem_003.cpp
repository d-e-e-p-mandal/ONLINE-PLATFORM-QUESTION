// GFG : 0 - 1 Knapsack Problem : Dynamic Programming (Tabulation) : Space Optimized
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
        vector<int>prev(W+1,0), curr(W+1);
        
        // Base case initialization : 1st row initllize of max(val[0], 0) each cel because we take max pick and notPick 
        for (int j = 0; j <= W; j++) {
            if (wt[0] <= j) prev[j] = val[0];
        }
        
        for(int i=1; i<n; i++){
            for(int j=0; j<=W; j++){
                int notPick = prev[j];//copy previous
                // taking index
                int pick = INT_MIN;
                if(wt[i] <= j) pick = val[i] + prev[j - wt[i]]; 
                //store maximum
                curr[j] = max(notPick, pick);
             }
             prev = curr;
        }
        
        return prev[W];
    }
};

int main() {
    Solution sol;
    int W = 10;
    vector<int> val = {60, 100, 120};
    vector<int> wt = {1, 2, 3};

    int result = sol.knapsack(W, val, wt);
    cout << "Maximum value in Knapsack = " << result << endl;
    return 0;
}
/*OUTPUT : Maximum value in Knapsack = 280*/
/*Time Complexity: O(n * W)
Space Complexity: O(n * W) + O(n) ← (DP table + recursion stack space) */