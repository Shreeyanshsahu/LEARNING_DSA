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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return false;

        ListNode *fast = head;
        ListNode *slow = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }
        return false;
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
    vector<int> nums = {-21,10,17,8,4,26,5,35,33,-7,-16,27,
                        -12,6,29,-12,5,9,20,14,14,2,13,-24,21,23,-21,5};

    // build linked list
    ListNode* head = buildList(nums);

    // make a cycle for testing (last node -> 2nd node)
    // comment this line if you want NO cycle
    head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = head->next;

    Solution s;
    cout << (s.hasCycle(head) ? "Cycle detected" : "No cycle") << endl;

    return 0;
}
