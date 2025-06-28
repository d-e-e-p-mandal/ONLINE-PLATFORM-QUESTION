// GFG : Geek's Training : Dynamic Programming : Tabulation (buttom up approach) Space optimisation

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        
        int n= arr.size();
        //store 1st day : we calculate next day and update dp array
        vector<int>dp(3);
        //initilize 1st day
        dp[0] = max(arr[0][1],arr[0][2]);
        dp[1] = max(arr[0][0],arr[0][2]);
        dp[2] = max(arr[0][0],arr[0][1]);
        
        // consecutively calculating day
        for(int day=1; day<n; day++){ 
            vector<int>temp(3);//temporary array take and  dp array will upadate by temp value

            for(int last = 0; last<3; last++){ //previous task
                int maxi = 0;
                // next task of last and different consequtive day
                for(int task = 0; task<3; task++){
                    if(task != last){
                        int point = arr[day][task] +dp[task]; //curr + previous maximum
                        maxi = max(maxi,point); //taking maximum
                    }
                }
                temp[last] = maxi; //update with maximum
            }
            dp = temp; //update dp value
        }
        
        return max(dp[0], max(dp[1], dp[2])); //ans is maximum of three
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
Space Complexity: O(3) → simplified as O(1)*/