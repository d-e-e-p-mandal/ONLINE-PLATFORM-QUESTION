//LeetCode : 70 : Climbing Stairs : Dynamic Programming : (Tabulation (Bottom-Up)) : Space Optimisation
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        // initilaze with 1 for each type of setep
        int prev1 = 1;
        int prev2 = 1;

        for(int i = 2; i<=n ; i++) {
            int curr = prev2 + prev1;
            //update
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

int main() {
    Solution sol;

    int n = 5; // Example input
    int result = sol.climbStairs(n);

    cout << "Number of ways to climb " << n << " stairs: " << result << endl;

    return 0;
}

/*Output : Number of ways to climb 5 stairs: 8*/
/*Time Complexity : O(N) 
Space Complexity : O(1) */