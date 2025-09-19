// LeetCode :  Egg Drop With 2 Eggs and N Floors : Math Solution : (Optimal Approach)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int twoEggDrop(int n) {
        // We need minimum number of moves m such that
        // 1 + 2 + 3 + ... + m >= n
        // (because with 2 eggs we can test floors incrementally in this way)
        
        int moves = 0;
        int testedFloors = 0;

        while (testedFloors < n) {
            moves++;
            testedFloors += moves;
        }

        return moves;
    }
};

int main() {
    Solution sol;

    int n1 = 10;
    cout << "For n = " << n1 << " floors -> Min moves = "
         << sol.twoEggDrop(n1) << endl;

    int n2 = 36;
    cout << "For n = " << n2 << " floors -> Min moves = "
         << sol.twoEggDrop(n2) << endl;

    int n3 = 100;
    cout << "For n = " << n3 << " floors -> Min moves = "
         << sol.twoEggDrop(n3) << endl;

    return 0;
}

/*
⚡ Complexity Analysis:

Time Complexity: O(sqrt(n))
 - Because sum of first m numbers = m(m+1)/2
 - We only loop until testedFloors >= n
 - So moves ≈ O(√n).

Space Complexity: O(1)
 - We only use a few variables.
*/