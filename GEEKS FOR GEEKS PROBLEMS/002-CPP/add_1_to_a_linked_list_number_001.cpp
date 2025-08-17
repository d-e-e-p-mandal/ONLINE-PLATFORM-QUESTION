// GFG : Add 1 to a Linked List Number : without reverse
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* addOne(Node* head) {
        Node *p = head;
        Node *t = head; // temp which triverse at the end to find not 9 number from right
        
        while(t != NULL){
            if(t->data != 9) p = t; // update with not 9 number
            t = t->next;
        }
        
        if(p != head || p->data != 9) {
            p->data = p->data + 1;
            p = p->next;
        }else{
            Node *new1 = new Node(1); // if all node 9
            new1 ->next = head;
            head = new1;
        }
        // after add 1, make all node 0 
        while(p != NULL){
            p->data = 0;
            p = p->next;
        }
        
        return head;
    }
};

// Utility function to create linked list from vector
Node* createList(const vector<int>& vals) {
    if(vals.empty()) return NULL;
    Node* head = new Node(vals[0]);
    Node* curr = head;
    for(size_t i = 1; i < vals.size(); i++) {
        curr->next = new Node(vals[i]);
        curr = curr->next;
    }
    return head;
}

// Utility function to print linked list
void printList(Node* head) {
    while(head != NULL) {
        cout << head->data;
        if(head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    // Example: 1 -> 9 -> 9
    vector<int> vals = {1, 9, 9};
    Node* head = createList(vals);
    
    cout << "Original list: ";
    printList(head);
    
    Solution sol;
    head = sol.addOne(head);
    
    cout << "After adding one: ";
    printList(head);
    
    return 0;
}

/* OUTPUT :
Original list: 1 -> 9 -> 9
After adding one: 2 -> 0 -> 0 */

/* Time Complexity : O(2 * N)
Space Complexity : O(1)*/