#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return NULL;

        ListNode *slow = head;
        ListNode *fast = head;

        // Step 1: Find meeting point if cycle exists
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Step 2: Reset one pointer to head
                ListNode *ptr1 = head;
                ListNode *ptr2 = slow;

                // Step 3: Move both one step at a time
                while (ptr1 != ptr2) {
                    ptr1 = ptr1->next;
                    ptr2 = ptr2->next;
                }

                return ptr1; // start of cycle
            }
        }
        return NULL; // no cycle
    }
};

// Helper function: build linked list from vector
ListNode* buildList(const vector<int>& arr) {
    if (arr.empty()) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    Solution s;

    // ---------- Test Case 1: Cycle ----------
    vector<int> nums1 = {3,2,0,-4};
    ListNode* head1 = buildList(nums1);

    // make a cycle (last node -> second node, index 1)
    ListNode* tail1 = head1;
    while (tail1->next != NULL) tail1 = tail1->next;
    tail1->next = head1->next; // cycle at node with value 2

    ListNode* cycleStart1 = s.detectCycle(head1);
    if (cycleStart1) {
        cout << "Cycle detected at node with value: " << cycleStart1->val << endl;
    } else {
        cout << "No cycle detected" << endl;
    }

    // ---------- Test Case 2: No Cycle ----------
    vector<int> nums2 = {1,2,3,4,5};
    ListNode* head2 = buildList(nums2);

    ListNode* cycleStart2 = s.detectCycle(head2);
    if (cycleStart2) {
        cout << "Cycle detected at node with value: " << cycleStart2->val << endl;
    } else {
        cout << "No cycle detected" << endl;
    }

    return 0;
}

