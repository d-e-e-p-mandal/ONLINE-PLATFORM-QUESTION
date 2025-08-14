//GFG : Knapsack with Duplicate Items : Dynamic Programming : Memoization
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        
        int n = val.size();
        vector<int> prev(capacity+1, 0); // dp
        
        // base case : index 0 : all element 0 : prev all element is 0 already we take it
        
        for(int i=1; i<=n; i++) {  // index start at 1 : index 0 in base case (index -1 is represented as 0 : using +1 with all index)
            for(int j=0; j<=capacity; j++) { // capacity
                int notPick = prev[j]; //not pick index
                
                int pick = 0;
                if(wt[i-1] <= j) pick = val[i-1] + prev[j-wt[i-1]]; // pick index : wt and val index 0 to n-1
                
                prev[j] = max(notPick, pick); // maximum of both
            }
        }
        
        
        return prev[capacity];
    }
};
int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int capacity = 50;

    Solution obj;
    int result = obj.knapSack(val, wt, capacity);

    cout << "Maximum value in Knapsack = " << result << endl;
    return 0;
}

/*OUTPUT : Maximum value in Knapsack = 220 */

/*
	Time Complexity: O(n * capacity) → Each state (ind, capacity) is computed once.
	Space Complexity: O(capacity) → O(capacity) for DP array.
*/