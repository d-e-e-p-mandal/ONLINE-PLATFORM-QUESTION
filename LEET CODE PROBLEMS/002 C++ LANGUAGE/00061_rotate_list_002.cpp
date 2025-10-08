// LeetCode : 61 : Rotate List : Optimal Solution
#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head; // empty list

        ListNode* newHead = head;
        ListNode* temp1 = head;
        ListNode* temp2 = head;

        // finding length and also point at end of list : temp1
        int length = 1;
        while (temp1->next) {
            length++;
            temp1 = temp1->next;
        }

        k %= length;
        if (k == 0) return head; // no change

        // move newHead and temp2
        for (int i = 0; i < length - k; i++) {
            temp2 = newHead;
            newHead = newHead->next;
        }

        temp2->next = NULL;   // last node before rotation
        temp1->next = head;   // connect end to old head

        return newHead;       // return new rotated head
    }
};

// Function to print linked list
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
   - One traversal to find length + one traversal for rotation.

💾 Space Complexity: O(1)
   - Only a few pointer variables used (no extra data structures).
*/