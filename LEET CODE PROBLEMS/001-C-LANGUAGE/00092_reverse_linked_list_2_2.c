// Leetcode : 92 : Reverse Linked List 2 : Recursion
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head, int right) {
    if(right == 0) return head; // if it reach right node

    struct ListNode* newHead = reverseList(head->next, right - 1);
    head->next->next = head; // add in last : last node adress store in head next -> update 
   // head->next = NULL; //last node address will be null  // optional : this is used for only reverse linked list
    return newHead;
}

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode* prevList = head;

    struct ListNode* temp = head; // 
    for(int i=1; i<left; i++){
        prevList = temp;    // store where we store rever list address
        temp = temp -> next;
    }

    struct ListNode *nextList = temp; // store where last part sote in node
    struct ListNode* lastPart = temp; // use to store last part of linked list

    for(int i=left; i<=right; i++) lastPart = lastPart ->next; // last part of linked list

    struct ListNode *reverseHead = reverseList(temp, right - left); // reversepart

    
    prevList -> next = reverseHead; // 1st part -> reverse part
    nextList -> next = lastPart; // reverse part -> last part

    // if reverse form starting point then head update to reverseHead
    return (left == 1) ? reverseHead : head;
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
Space Complexity : O(n)recursion stack*/