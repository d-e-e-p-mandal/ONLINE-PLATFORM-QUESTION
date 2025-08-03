// GFG : Perfect Sum Problem : Dynamic programming (Tabulation) : Space Optimized

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int>prev(target+1, 0), curr(target+1);
        // column represent target : arr[i] can achive target 
        // base case target 0 always achive because not pick all : 1 
        prev[0] = curr[0] = 1;
        
        if(arr[0] <= target) prev[arr[0]]= 1; // 1st only q true set by direct
        if(arr[0] == 0) prev[0] = 2; 
        
        for(int i=1; i<n; i++){
            for(int j=0; j<=target; j++){
                // copy old result not picking this
                int notPick = prev[j];
                // with pick
                int pick = 0;
                if(arr[i] <= j)
                    pick = prev[j-arr[i]];
                // ans : notPick + pick
                curr[j] = notPick + pick;
            }
            prev = curr;
        }
        
        return prev[target];
    }
};

int main() {
    vector<int> arr = {0, 0, 1};
    int target = 1;

    Solution sol;
    int result = sol.perfectSum(arr, target);

    cout << "Number of subsets with sum " << target << " = " << result << endl;

    return 0;
} 

/* Output : Number of subsets with sum 1 = 4 */
/*Time Complexity: O(n * target)
Space Complexity: O(target)*/