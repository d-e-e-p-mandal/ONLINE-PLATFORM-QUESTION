// LEETCODE : 2929: Distribute Candies Among Children II
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        // asume two child
        int minChild1 = max(0, n - 2 * limit);
        int maxChild1 = min(n, limit);
        long long count = 0;

        // last two divide another two child
        for (int i = minChild1; i <= maxChild1; i++) {
            int N = n - i;

            int minChild2 = max(0, N - limit);
            int maxChild2 = min(N, limit);

            // total ways : for every : maximum - minimum + 1
            count += maxChild2 - minChild2 + 1;
        }
        return count;
    }
};

int main() {
    Solution sol;
    int n, limit;
    
    // Example usage:
    cout << "Enter total candies (n): ";
    cin >> n;
    cout << "Enter limit per child: ";
    cin >> limit;

    long long result = sol.distributeCandies(n, limit);
    cout << "Number of ways to distribute candies: " << result << endl;

    return 0;
}

/*OUTPUT :
Enter total candies (n): 5
Enter limit per child: 2
Number of ways to distribute candies: 6
*/