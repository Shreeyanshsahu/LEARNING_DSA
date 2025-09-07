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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* a = head;        // odd-positioned pointer
        ListNode* b = head->next;  // even-positioned pointer
        ListNode* c = b;           // store head of even list

        while (a->next != NULL && b->next != NULL) {
            a->next = b->next;     // link odd to next odd
            a = a->next;           // move odd forward
            b->next = a->next;     // link even to next even
            b = b->next;           // move even forward
        }

        a->next = c;  // connect end of odd-positioned list to even list
        return head;
    }
};

// Helper to print list (for debugging in VS Code)
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    ListNode* newHead = sol.oddEvenList(head);

    printList(newHead);  // Output: 1 -> 3 -> 5 -> 2 -> 4
}
