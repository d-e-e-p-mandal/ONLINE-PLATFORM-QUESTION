// GFG : Rod Cutting : Dynamic Programming : Tabulation
#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution {
  public:
    int cutRod(vector<int> &price) {
        // length of rod is size of array
        int n = price.size();
        vector<int> prev(n+1, 0), curr(n+1); // dp
        // base case : index 0 means rod length 1 : total price = total lenght * price[0] / 1;
        for(int j=0; j<=n; j++) {
            prev[j] = j * price[0]; // price of all size length by 1 length
        }
        
        for(int i=1; i<n; i++) { // index
            for(int j=0; j<=n; j++) {   // length of rod
                int notTake = prev[j]; // notPick
                // pcilk
                int take = INT_MIN; // or 0
                if(i+1 <= j) take = price[i] + curr[j-(i+1)]; //length = index + 1 and same index repeatedly can cut
                
                curr[j] = max(notTake, take);
            }
            
            prev = curr;
        }
        
        return prev[n];
    }
};

int main() {
    // Sample Input
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};

    Solution obj;
    cout << obj.cutRod(price) << endl; // Expected Output: 22
    return 0;
}

/* OUTPUT : 22 */
/*Time Complexity: O(n²), Space Complexity: O(2n) (DP table).*/
