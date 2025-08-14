// LeetCode : 142 : Linked List cycle 2
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

/* ---------- Your Original Code (unchanged) ---------- */
struct ListNode *detectCycle(struct ListNode *head) {
    // if it has no Node or only one node with NULL pointer
    if(head == NULL || head -> next == NULL) return false;

    struct ListNode *slow = head->next; // slow pointer jump 1 Node
    struct ListNode *fast = head->next->next; // fast pointer jump 2 Node
    
    // if it has cycle then loop will be terminated
    while(slow != fast){
        if(slow == NULL || fast == NULL || fast->next == NULL) return false; // if it has no cycle
        slow = slow->next; // jump 1
        fast = fast->next->next; // jump 2
    }
    
    // find last node pointing which node
    // where slow and fast at same node : point - slow at head now traverse both 1 by one node where both meet
    slow = head;
    while(slow != fast) {
        slow = slow ->next;
        fast = fast -> next;
    }

    return fast; // fast || slow
}
/* ---------------------------------------------------- */

// Helper to create a new node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

int main() {
    // Example 1: List with a cycle
    struct ListNode* head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(3);
    head1->next->next->next = newNode(4);
    head1->next->next->next->next = head1->next; // create cycle (4 → 2)

    struct ListNode* cycleNode1 = detectCycle(head1);
    if (cycleNode1)
        printf("List 1 cycle starts at node with value: %d\n", cycleNode1->val);
    else
        printf("List 1 has no cycle\n");

    // Example 2: List without a cycle
    struct ListNode* head2 = newNode(10);
    head2->next = newNode(20);
    head2->next->next = newNode(30);

    struct ListNode* cycleNode2 = detectCycle(head2);
    if (cycleNode2)
        printf("List 2 cycle starts at node with value: %d\n", cycleNode2->val);
    else
        printf("List 2 has no cycle\n");

    return 0;
}

/* OUPUT :
List 1 cycle starts at node with value: 2
List 2 has no cycle*/

/*Time Complexity: O(n) Space Complexity: O(1)*/