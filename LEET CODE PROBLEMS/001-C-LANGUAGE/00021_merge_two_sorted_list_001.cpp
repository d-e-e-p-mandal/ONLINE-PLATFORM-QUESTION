// LeetCodee : 21 : Linked List : Merge Two Sorted Lists

#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to merge two sorted linked lists
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if(list1 == NULL) return list2; // if list1 is empty
    if(list2 == NULL) return list1; // if list2 is empty

    // recursive merge
    if(list1->val < list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    list2->next = mergeTwoLists(list1, list2->next);
    return list2;
}

// Utility: create new node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Utility: print list
void printList(struct ListNode* head) {
    while(head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // First sorted list: 1 -> 3 -> 5
    struct ListNode* list1 = newNode(1);
    list1->next = newNode(3);
    list1->next->next = newNode(5);

    // Second sorted list: 2 -> 4 -> 6
    struct ListNode* list2 = newNode(2);
    list2->next = newNode(4);
    list2->next->next = newNode(6);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    // Merge the two lists
    struct ListNode* merged = mergeTwoLists(list1, list2);

    printf("Merged List: ");
    printList(merged);

    return 0;
}

/*
List 1: 1 3 5 
List 2: 2 4 6 
Merged List: 1 2 3 4 5 6
*/

/*Time Complexity: O(n + m), Space Complexity: O(n + m) (recursion stack).*/