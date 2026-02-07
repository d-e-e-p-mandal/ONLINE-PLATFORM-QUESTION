#include <bits/stdc++.h>
using namespace std;

// Function to process ATM withdrawal
void solve(int withdraw_balance, double account_balance) {
    // Check if withdrawal amount is a multiple of 5
    // and if sufficient balance is available including bank charge
    if (withdraw_balance % 5 == 0 && withdraw_balance + 0.5 <= account_balance) {
        cout << fixed << setprecision(2)
             << account_balance - withdraw_balance - 0.5;
    } else {
        // If conditions fail, print original balance
        cout << fixed << setprecision(2)
             << account_balance;
    }
}

int main() {
    ios::sync_with_stdio(false);
    // cin.tie(nullptr);  // Optional for this problem

    int x;
    double y;
    cin >> x >> y;   // x = withdrawal amount, y = account balance

    solve(x, y);

    return 0;
}

/*
Time Complexity:
- O(1), constant time operations.

Space Complexity:
- O(1), constant extra space.
*/