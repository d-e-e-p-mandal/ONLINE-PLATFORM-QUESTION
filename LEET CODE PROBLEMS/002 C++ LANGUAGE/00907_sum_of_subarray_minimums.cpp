// Leetcode : 907 : Sum of Subarray Minimums
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        int mod = 1e9 + 7;
        
        vector<int>pge(n),nge(n);

        //Previous Greater Element
        {   
            stack<int>st; // to auto destroy stack we write this code in block for skip to empty the stack loop
            for(int i=0; i<n; i++){
                while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
                pge[i] = st.empty() ? -1 : st.top();
                st.push(i);
            }
        }
        
        // while(!st.empty()) st.pop(); //empty stack

        //Next Greater Element
        {   
            stack<int>st;
            for(int i =n-1; i>=0 ; i--){
                while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
                nge[i] = st.empty() ? n : st.top();
                st.push(i);
            }
        }
        /*Total number of subarray = N*(N+1)/2, any index is present in subarray = M*N, M = lenght of left side and N = length of right side
        [6,7,8,2,3,4,6]  index 3 element in 4*3 = 12 subarray : */
        for(int i =0; i<n; i++){
            int left = i - pge[i];
            int right = nge[i] - i;
            res = (res + (long long)left * right * arr[i]) % mod; //type casting in long cause multile can be greater than int
        }
        return res;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements:\n";
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    Solution sol;
    int result = sol.sumSubarrayMins(arr);
    cout << "Sum of subarray minimums: " << result << endl;

    return 0;
}
/*OUTPUT : 
Enter number of elements: 4
Enter elements:
3 1 2 5

Sum of subarray minimums: 18
*/

/* Time Complextiy : O(2N) -> O(N)
Space Comlexity : O(3N) -> O(N)*/