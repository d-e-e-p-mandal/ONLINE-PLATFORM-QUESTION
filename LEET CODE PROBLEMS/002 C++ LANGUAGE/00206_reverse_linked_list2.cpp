// Leetcode : 206 : Reverse Linked List : Reverse link
#include <iostream>
#include <stack>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr)return head;
        ListNode *prev, *temp;
        prev = head;
        head = head -> next;
        prev->next = nullptr; // it will be the last node so its next will be NULL
        while(head != nullptr){
            temp = head -> next; //store the head next part
            head -> next = prev; //linked as reverse

            prev = head; //shifting previous which wil be link to next
            head = temp; //trivese
        }

        return prev;
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    while(head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Function to create a sample linked list
ListNode* createList() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    return head;
}

int main() {
    // Create sample linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    ListNode* head = createList();
    
    cout << "Original List: ";
    printList(head);

    Solution sol;
    head = sol.reverseList(head);

    cout << "Reversed List (by value): ";
    printList(head);

    return 0;
}

/*OUTPUT :
Original List: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
Reversed List (by link): 5 -> 4 -> 3 -> 2 -> 1 -> NULL */