// GFG : Geek's Training : Dynamic Programming : Tabulation (buttom up approach) 

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        
        int n= arr.size();
        // to store previous value, using 2D dp 
        vector<vector<int>>dp(n,vector<int>(3,0)); //vector<vector<int>>dp(n,vector<int>(4,0)); 
        //intilize 1st day (index 0 of array)
        dp[0][0] = max(arr[0][1],arr[0][2]);
        dp[0][1] = max(arr[0][0],arr[0][2]);
        dp[0][2] = max(arr[0][0],arr[0][1]);
        //dp[0][3] = max(arr[0][0],max(arr[0][1],arr[0][2]));
        
        //interation of each day
        for(int day=1; day<n; day++){ 
            //we will update dp so that no consequtive day perform same task, last means data stored as previous
            for(int last = 0; last<3; last++){ 
                int maxi = 0;
                for(int task = 0; task<3; task++){ //copy memoisation approach : task with different with previous day
                    if(task != last){
                        int point = arr[day][task] +dp[day-1][task]; //curr + previous(max)
                        maxi = max(maxi,point); //update with maxmimum with previos+current
                    }
                }
                dp[day][last] = maxi; //update as last
                
            }
        }
        
       // return dp[n-1][3];
        return max(dp[n-1][0], max(dp[n-1][1],dp[n-1][2]));
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
Space Complexity: O(N * 3) → simplified as O(N)*/