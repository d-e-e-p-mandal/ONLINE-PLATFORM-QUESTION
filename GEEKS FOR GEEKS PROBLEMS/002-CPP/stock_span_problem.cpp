// GFG : Stock Span Problem : (stack)
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        stack<int>st;
        vector<int>ans;
        
        for(int i=0; i<arr.size(); i++){
            while(!st.empty() && arr[st.top()] <= arr[i]) //consecutive less than or equal
                st.pop();
                
            int price = st.empty() ? i+1 : i - st.top(); // calculate number of small numbers in between
            ans.push_back(price);
            st.push(i);
        }
        
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter stock prices:\n";
    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    Solution sol;
    vector<int> spans = sol.calculateSpan(prices);

    cout << "Stock span values:\n";
    for(int val : spans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

/*OUTPUT : Enter number of days: 7
Enter stock prices:
100 80 60 70 60 75 85

Stock span values:
1 1 1 2 1 4 6*/

/*Time Complexity: O(n)  
Space Complexity: O(n)*/