// Leetcode : 92 : Reverse Linked List 2
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode *temp = head;
    
    struct ListNode *prevList = head; // use to store (left - 1 )node address
    
    for(int i=1; i<left; i++){
        prevList = temp;
        temp = temp -> next;
    }
    struct ListNode *nextList = temp; // use to store (right + 1) node address

    // reverse list
    struct ListNode *tempHead = temp; 
    struct ListNode *curr = temp;
    struct ListNode *nextNode = temp->next;

    //tempHead -> next = NULL; // optional : this is used for only reverse linked list

    for(int i=left; i<right; i++){
        curr = nextNode;
        nextNode = nextNode -> next;

        curr->next = tempHead;
        tempHead = curr;
    }
    // 1st part -> reverse part -> last part
    prevList->next = tempHead;
    nextList->next = nextNode;

    // if reverse from starting point then head will point reverse list head
    return (left == 1)? tempHead : head;
}

// Helper to create new node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Helper to print list
void printList(struct ListNode* head) {
    struct ListNode* temp = head;
    while(temp != NULL) {
        printf("%d", temp->val);
        if(temp->next) printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Create list: 1 -> 2 -> 3 -> 4 -> 5
    struct ListNode* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    printf("Original list: ");
    printList(head);

    int left = 2, right = 4;
    head = reverseBetween(head, left, right);

    printf("List after reversing between %d and %d: ", left, right);
    printList(head);

    // Free memory
    struct ListNode* curr = head;
    while(curr != NULL) {
        struct ListNode* next = curr->next;
        free(curr);
        curr = next;
    }

    return 0;
}

/* Original list: 1 -> 2 -> 3 -> 4 -> 5
List after reversing between 2 and 4: 1 -> 4 -> 3 -> 2 -> 5 */

/* Time Complexity : O(N)
Space Complexity : O(1)*/