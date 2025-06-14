// LEETCODE : 328 : Odd Even Linked List
#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !(head->next)) return head; // if less than 2 node
        
        // for odd node
        ListNode *oddHead = new ListNode(head->val);
        ListNode *oddCur = oddHead;

        // for even node
        ListNode *evenHead = new ListNode(head->next->val);
        ListNode *evenCur = evenHead;

        ListNode *cur = head->next->next; // for traverse original linked list

        while(cur != nullptr && cur->next != nullptr) {
            oddCur->next = new ListNode(cur->val);
            oddCur = oddCur->next;

            evenCur->next = new ListNode(cur->next->val);
            evenCur = evenCur->next;

            cur = cur->next->next;
        }

        // if origin linked list odd length
        if(cur) {
            oddCur->next = new ListNode(cur->val);
            oddCur = oddCur->next;
        }

        oddCur->next = evenHead;

        return oddHead;
    }
};

// Helper function to create linked list from array
ListNode* createList(const vector<int>& vals) {
    if(vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for(size_t i = 1; i < vals.size(); ++i) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print linked list
void printList(ListNode* head) {
    while(head) {
        cout << head->val;
        if(head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> input = {1, 2, 3, 4, 5};
    ListNode* head = createList(input);

    cout << "Original list: ";
    printList(head);

    Solution sol;
    ListNode* result = sol.oddEvenList(head);

    cout << "Odd-Even reordered list: ";
    printList(result);

    return 0;
}

/*OUTPUT : 
Original list: 1 -> 2 -> 3 -> 4 -> 5
Odd-Even reordered list: 1 -> 3 -> 5 -> 2 -> 4
*/
/*Time Complexity : O(N)*/