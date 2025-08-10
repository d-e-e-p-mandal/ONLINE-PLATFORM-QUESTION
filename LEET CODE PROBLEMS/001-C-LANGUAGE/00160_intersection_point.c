// Leetcode : 160 : Intersection of Two Linked Lists
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *tA = headA;
    struct ListNode *tB = headB;
    int lenA = 0;
    int lenB = 0;
    // calculate length of A
    while(tA != NULL) {
        lenA++;
        tA = tA -> next;
    }
    // calculate length of B
    while(tB != NULL) {
        lenB++;
        tB = tB -> next;
    }

    tA = headA;
    tB = headB;
    // move the longer list's pointer ahead by difference in lengths
    if(lenA - lenB > 0) {
        int traverse = lenA - lenB;
        while(traverse--) {
            tA = tA->next;
        }
    } else {
        int traverse = lenB - lenA;
        while(traverse--) {
            tB = tB->next;
        }
    }
    // move both pointers until intersection found or end reached
    while(tA != tB && tA != NULL) {
        tA = tA->next;
        tB = tB->next;
    }
    return tA; // intersection node or NULL
}

// Helper to create new node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

int main() {
    // Creating two linked lists that intersect
    
    // List A: 1 -> 2 -> 3
    struct ListNode* headA = newNode(1);
    headA->next = newNode(2);
    headA->next->next = newNode(3);

    // List B: 6 -> 7
    struct ListNode* headB = newNode(6);
    headB->next = newNode(7);

    // Creating intersection: List B's next points to List A's node with value 2
    headB->next->next = headA->next; // Intersection at node with value 2

    struct ListNode* intersection = getIntersectionNode(headA, headB);

    if(intersection) {
        printf("Intersection at node with value: %d\n", intersection->val);
    } else {
        printf("No intersection found.\n");
    }

    // Freeing nodes: careful to avoid double free on intersection nodes
    free(headB->next); // node with val 7
    free(headB);       // node with val 6
    free(headA->next->next); // node with val 3
    free(headA->next);       // node with val 2 (shared)
    free(headA);             // node with val 1

    return 0;
}

/*Output : Intersection at node with value: 2*/
/*Time Complexity : O(M+N)
Space Complexity : O(1)*/