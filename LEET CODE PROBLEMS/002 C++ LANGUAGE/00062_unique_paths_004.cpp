//LeetCode : 62 : Unique Path : Dynamic Programming : Math (probability)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // from (0,0) to (m,n) => (m+n)!/m!*n! (maths : P&C)
    int uniquePaths(int m, int n) { // here (0,0) to (m-1,n-1)
        long long res = 1;
        for(int i = 1; i <= m - 1; i++) {
            res = res * (n - 1 + i) / i;
        }
        return (int)res;
    }
};

int main() {
    Solution sol;
    int m, n;
    cout << "Enter number of rows (m): ";
    cin >> m;
    cout << "Enter number of columns (n): ";
    cin >> n;

    int result = sol.uniquePaths(m, n);
    cout << "Number of unique paths: " << result << endl;

    return 0;
}