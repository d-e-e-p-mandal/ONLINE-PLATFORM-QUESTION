//GFG : Smaller on Left : 
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> leftSmaller(vector<int> arr) {
        vector<int> ans;
        stack<int> st;
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && st.top() >= arr[i]) st.pop(); //until top element is greater then arr[i]

            if (st.empty()) ans.push_back(-1);
            else ans.push_back(st.top());

            st.push(arr[i]);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 3, 0, 2, 5};
    vector<int> result = sol.leftSmaller(arr);

    cout << "Left smaller elements: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
/* OUTPUT : Left smaller elements: -1 1 -1 0 2 */