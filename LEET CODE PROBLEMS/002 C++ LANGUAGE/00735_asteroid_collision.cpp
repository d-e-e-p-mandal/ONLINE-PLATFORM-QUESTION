//Leetcode : 735 : Asteroid Collision : using stack :(better approach : use deque)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        
        for(int i=0; i<asteroids.size(); i++){
            bool destroied = false;
            while(!st.empty() && asteroids[i] < 0 && st.top() > 0){ //if -ve number  <- (left direction and +ve number -> (right direction)) and also for previou collision
                if(abs(st.top()) == abs(asteroids[i])) { //both collision if equal
                    st.pop();
                    destroied = true;
                    break;
                }
                else if(abs(st.top()) < abs(asteroids[i])){
                    st.pop();
                }
                else{
                    destroied = true;
                    break;
                }
            }
            if(!destroied) st.push(asteroids[i]); //if not distoried push it
        }
        vector<int>ans(st.size());
        
        for(int i = st.size() - 1; !st.empty(); i--){
            ans[i] = st.top();
            st.pop();
        }

        /* using push back
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return vector<int>(ans.rbegin(), ans.rend());
        */

        return ans;
    }
};

int main() {
    Solution sol;

    // Sample input: asteroid collisions
    vector<int> asteroids = {5, 10, -5};

    // Function call
    vector<int> result = sol.asteroidCollision(asteroids);

    // Output the result
    cout << "Remaining asteroids after collisions: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

/* OUTPUT : Remaining asteroids after collisions: 5 10 */

/*Time Complexity : O(N)
Space Complexity : O(N)*/