//Leetcode : 239 : Sliding Window Maximum 
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        // max element in stack between k range in nums will be apear at front of deque
        for(int i = 0; i<k-1; i++){ //push number of element 0 to k-1
            while(!dq.empty() && nums[dq.back()] < nums[i]){ //if from current then remove it
                dq.pop_back();
            }
            dq.push_back(i);
        }

        for(int i = k-1; i<nums.size(); i++){
            while(!dq.empty() && nums[dq.back()] < nums[i]){ //if from current then remove it
                dq.pop_back();
            }
            if(!dq.empty() && dq.front() <= i - k) dq.pop_front(); //remove if it not in range
            dq.push_back(i);

            ans.push_back(nums[dq.front()]); //store max element
        }

        return ans;
    }
};

int main() {
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter window size k: ";
    cin >> k;

    Solution sol;
    vector<int> result = sol.maxSlidingWindow(nums, k);

    cout << "Sliding window maximums: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

/*OUTPUT : Enter number of elements: 8
Enter the elements:
1 3 -1 -3 5 3 6 7
Enter window size k: 3

Sliding window maximums: 3 3 5 5 6 7
*/

/*Time Complexity: O(n) 
Space Complexity: O(k)*/