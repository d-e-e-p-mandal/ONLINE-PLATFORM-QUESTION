#include <bits/stdc++.h>
using namespace std;

// Function to compute minimum number of swaps
// to bring the maximum element to the front
// and the minimum element to the end
void solve(vector<int>& arr, int n) {

    int minInd = 0, maxInd = 0; // Indices of minimum and maximum elements
    int ans = 0;

    // Find index of minimum (last occurrence)
    // and maximum (first occurrence)
    for (int i = 1; i < n; i++) {
        if (arr[i] <= arr[minInd]) minInd = i;
        if (arr[i] > arr[maxInd])  maxInd = i;
    }

    // Swaps needed:
    // - Bring min element to the end
    // - Bring max element to the front
    ans = (n - minInd - 1) + maxInd;

    // If max element is originally after min element,
    // one swap is saved due to index shift
    ans = (maxInd > minInd) ? ans - 1 : ans;

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr); 

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    // cin >> t;   // Single test case for this problem
    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) 
            cin >> arr[i];

        solve(arr, n);
    }
}

/*
Time Complexity:
- O(n), where n is the number of elements.
- Single traversal to find min and max indices.

Space Complexity:
- O(1) extra space (excluding input array).
*/