// Leetcode : 141 : Linked List cycle 
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
bool hasCycle(struct ListNode *head) {
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
    
    return true; // if loop terminated
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

    if (hasCycle(head1))
        printf("List 1 has a cycle\n");
    else
        printf("List 1 has no cycle\n");

    // Example 2: List without a cycle
    struct ListNode* head2 = newNode(10);
    head2->next = newNode(20);
    head2->next->next = newNode(30);

    if (hasCycle(head2))
        printf("List 2 has a cycle\n");
    else
        printf("List 2 has no cycle\n");

    return 0;
}

/* OUTPUT : 
List 1 has a cycle
List 2 has no cycle */
/* Time Complexity : O(N)
Space Complexity : O(1) */