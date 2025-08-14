// GFG : Flattening a Linked List
#include <bits/stdc++.h>
using namespace std;

/* Node structure  used in the program */
struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

class Solution {
  public: 
    Node *mergeLL(Node* headA, Node* headB){
        Node *dummyNode = new Node(-1); // create a dummy node
        Node *res = dummyNode;
        
        // merge in shorted order, List -> bottom
        while(headA != NULL && headB != NULL){
            if(headA->data < headB->data) {
                res -> bottom = headA;
                res = headA;
                headA = headA->bottom;
            }
            else{
                res -> bottom = headB;
                res = headB;
                headB = headB->bottom;
            }
            
            res->next = NULL; // make next pointer NULL of each node
        }
        
        // add remaining linked list at the bottom
        if(headA != NULL ) res->bottom = headA;
        else res->bottom = headB;
        
        // res is after the dummyNode and delete dummyNode
        res = dummyNode -> bottom;
        delete dummyNode;
        
        //if(res != NULL) res->next = NULL; // this is optional res->next is already null in while loop
        
        return res;
    }
  public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // base case : if root is Null or only one Node
        if(root == NULL || root->next == NULL) return root;
        
        // recursively go to the last and merge last two node and next = NULL
        Node* mergedHead = flatten(root->next);
        
        root = mergeLL(root, mergedHead); //merge Last two column
        
        return root; //return after merge
    }
};

// Helper function to print bottom-linked list
void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->bottom;
    }
    cout << "\n";
}

int main() {
    /* 
       Example linked list:
       5 -> 10 -> 19 -> 28
       |     |     |     |
       7     20    22    35
       |           |     |
       8           50    40
       |                 |
       30                45
    */
    
    Node* head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(19);
    head->next->next->next = new Node(28);

    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next->bottom = new Node(20);

    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom = new Node(45);

    Solution sol;
    Node* flatHead = sol.flatten(head);

    printList(flatHead);

    return 0;
}

/*OUTPUT : 5 7 8 10 19 20 22 28 30 35 40 45 50 */
/*Time Complexity: O(n) average, O(n × k) worst case (skewed merges)
Space Complexity: O(k) recursion stack, O(1) extra auxiliary space*/