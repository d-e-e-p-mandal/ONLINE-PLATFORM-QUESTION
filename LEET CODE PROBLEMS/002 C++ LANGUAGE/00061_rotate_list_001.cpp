// LeetCode : 61 : Rotate List : Naive Solution

#include <bits/stdc++.h>
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;  // Empty list case

        int n = 0;
        ListNode* temp1 = head;
        ListNode* temp2 = head;

        // Count total nodes
        while (temp1) {
            n++;
            temp1 = temp1->next;
        }

        k %= n; // handle k > n
        if (k == 0) return head;

        int tempCnt = n - k;
        temp1 = head;

        // Move temp1 to (n - k)th node and temp2 to one before it
        while (tempCnt) {
            temp2 = temp1;
            temp1 = temp1->next;
            tempCnt--;
        }

        // Break the link
        temp2->next = NULL;

        // Move to the end of rotated part
        ListNode* temp3 = temp1;
        while (temp3->next) {
            temp3 = temp3->next;
        }

        // Connect last node to old head
        temp3->next = head;

        // Return new head
        return temp1;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    int k = 2;

    cout << "Original List: ";
    printList(head);

    ListNode* rotated = sol.rotateRight(head, k);

    cout << "Rotated List by " << k << ": ";
    printList(rotated);

    return 0;
}

/*
-----------------------------------------
🧩 Example Output:
Original List: 1 -> 2 -> 3 -> 4 -> 5
Rotated List by 2: 4 -> 5 -> 1 -> 2 -> 3
-----------------------------------------

⏱️ Time Complexity:  O(N)
   - One traversal to count nodes + one for rotation.

💾 Space Complexity: O(1)
   - Only pointers used, no extra memory.
*/