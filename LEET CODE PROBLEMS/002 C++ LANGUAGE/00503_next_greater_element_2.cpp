//LEETCODE : 509 : Next greate Element 2
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        // Traverse the array twice to simulate circular array
        for(int i = 2 * n - 1; i >= 0; i--) {
            int idx = i % n;
            while(!st.empty() && st.top() <= nums[idx]) {
                st.pop();
            }

            if(i < n) { // Only assign answers in the first pass
                if(!st.empty())
                    ans[idx] = st.top();
                else ans[idx] = -1;
            }

            st.push(nums[idx]);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1};  // Example input
    vector<int> result = sol.nextGreaterElements(nums);

    cout << "Next Greater Elements: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
/*Next Greater Elements: 2 -1 2*/