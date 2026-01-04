// LeetCode : 1390 : Four Divisors

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Check whether a number is prime
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }

    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;

        for (int num : nums) {

            // Case 1: num = p^3 (p is prime)
            int p = round(cbrt(num));
            if (p * p * p == num && isPrime(p)) {
                sum += (1 + p + p * p + num);
                continue;
            }

            // Case 2: num = p * q (p and q are distinct primes)
            for (int d = 2; d * d <= num; d++) {
                if (num % d == 0) {
                    int other = num / d;

                    if (d != other && isPrime(d) && isPrime(other)) {
                        sum += (1 + d + other + num);
                    }
                    break; // only one factor pair allowed
                }
            }
        }

        return sum;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    Solution obj;
    cout << obj.sumFourDivisors(nums) << endl;

    return 0;
}

/*
-----------------------------------------
Sample Input:
4
21 4 7 10

Sample Output:
32

Explanation:
21 → divisors: 1, 3, 7, 21 → sum = 32
4, 7, 10 → do not have exactly four divisors

-----------------------------------------
Time Complexity:
O(n * sqrt(m))
Where m is the maximum value in nums.
Reason:
For each number, we check divisors up to sqrt(num).

Space Complexity:
O(1)
Reason:
Only constant extra space used.

-----------------------------------------
*/