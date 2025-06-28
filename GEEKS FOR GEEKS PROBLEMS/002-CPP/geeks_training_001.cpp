// GFG : Geek's Training : Dynamic Programming : Memoization (top - down approach)
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int totalPoint(vector<vector<int>> &arr, int index, int last, vector<vector<int>> &dp){
        /*if(index == 0){
            int maxi = 0;
            for(int task = 0; task<3; task++) {
                if(task != last){
                    maxi = max(maxi, arr[index][task]);
                }
            }
            return maxi;
        }*/
        if(index == -1)return 0; // same as previous comment of block
        
        if(dp[index][last] != -1) return dp[index][last];
        
        int maxi = 0;
        for(int task = 0; task < 3; task++){
            if(task != last){ //can not perfome same task on consecutive day
                maxi = max(maxi,arr[index][task] + totalPoint(arr, index - 1, task, dp)); //check all combination
            }
        }
        return dp[index][last] = maxi;
    }
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        
        int n= arr.size();
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return totalPoint(arr, n-1, 3, dp); //no task perform intitally so send (3) out of index
    }
};

int main() {
    int n;
    cin >> n; // number of days

    vector<vector<int>> arr(n, vector<int>(3));
    
    // input task points for each day
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 3; ++j){
            cin >> arr[i][j];
        }
    }

    Solution sol;
    cout << sol.maximumPoints(arr) << endl;

    return 0;
}

/*Output : 
3
10 50 40
30 20 50
20 60 70

180*/

/*Time Complexity: O(N * 4 * 3) → simplified as O(N)
Space Complexity: O(N * 4) → simplified as O(N)*/