// Leetcode : 402 : Remove k Digits : (better using deque)
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        string ans;
        for(int i=0; i<num.size(); i++) {
            if(st.empty() || st.top() <= num[i] || k==0){
               if(num[i] == '0' && st.empty())continue; //if 0 at the started position then skip
                st.push(num[i]);
            }
            else {
                while(!st.empty() && st.top() > num[i] && k>0){
                    st.pop();k--;
                }
                if(num[i] == '0' && st.empty())continue; ////if 0 at the started position then skip
                st.push(num[i]);
            }
        }

        while(k>0 && !st.empty()) { //eg. "12345'  accnding then remove from back remaing k digit
            st.pop();k--;
        }

        while (!st.empty()) { 
            ans += st.top();  // adds chars in reverse order
            st.pop();
        }
        reverse(ans.begin(), ans.end()); //reverse the ans

        return ans.empty() ? "0" : ans;
    }
};

int main() {
    string num;
    int k;
    
    cout << "Enter the number string: ";
    cin >> num;
    
    cout << "Enter the value of k: ";
    cin >> k;

    Solution sol;
    string result = sol.removeKdigits(num, k);
    
    cout << "Smallest number after removing " << k << " digits: " << result << endl;
    return 0;
}

/*OUTPUT : Enter the number string: 1432219
Enter the value of k: 3 
Smallest number after removing 3 digits: 1219
*/

/*Time Complexity: O(n)  
Space Complexity: O(n)*/