// LEETCODE : 2 : Add Two Numbers : Linked List

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *headRes, *current;
        headRes = current = nullptr;

        int carry = 0;
        while (l1 != nullptr || l2 != nullptr) {
            // sum calculation
            int sum = carry;
            if (l1) sum += l1->val;
            if (l2) sum += l2->val;

            // store sum in new linked list
            ListNode *temp = new ListNode(sum % 10);
            if (!headRes) {
                headRes = temp;
                current = headRes;
            } else {
                current->next = temp;
                current = current->next;
            }
            carry = sum / 10;

            // traverse
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry) current->next = new ListNode(carry);

        return headRes;
    }
};

// Helper function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode *head = new ListNode(arr[0]);
    ListNode *current = head;
    for (int i = 1; i < size; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example input: (2 -> 4 -> 3) + (5 -> 6 -> 4) = 7 -> 0 -> 8
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};

    ListNode* l1 = createList(arr1, 3);
    ListNode* l2 = createList(arr2, 3);

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result);

    return 0;
}
/*OUTPUT :
7 -> 0 -> 8
*/
/*Time Complexity : O(MAX(M,N))*/