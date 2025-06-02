// Leetcode : 155 : Min Stack
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    long long min;
    stack<long long>st;
    MinStack(){}
    
    void push(int val) {
        if(st.empty()){
            min = val;
            st.push(val);
        }
        else if(min <= val){
            st.push(val);
        }
        else{
            st.push(2LL*val - min);
            min = val;
        }
    }
    
    void pop() {
        if (st.empty()) return;

        if (st.top() < min) {
            min = 2LL * min - st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.empty())return -1;
        if(min <= st.top())
            return st.top();
        return min;
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    MinStack* obj = new MinStack();

    obj->push(5);
    cout << "Pushed 5\n";
    cout << "Min: " << obj->getMin() << ", Top: " << obj->top() << "\n";

    obj->push(3);
    cout << "Pushed 3\n";
    cout << "Min: " << obj->getMin() << ", Top: " << obj->top() << "\n";

    obj->push(7);
    cout << "Pushed 7\n";
    cout << "Min: " << obj->getMin() << ", Top: " << obj->top() << "\n";

    obj->pop();
    cout << "Popped\n";
    cout << "Min: " << obj->getMin() << ", Top: " << obj->top() << "\n";

    obj->pop();
    cout << "Popped\n";
    cout << "Min: " << obj->getMin() << ", Top: " << obj->top() << "\n";

    delete obj;
    return 0;
}