#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
    // Bubble-sort style partition
    ListNode* partitionbubble(ListNode* head, int x) {
        if (!head)
            return head;

        bool swapped;
        ListNode* ptr;
        ListNode* lptr = NULL;

        do {
            swapped = false;
            ptr = head;

            while (ptr->next != lptr) {
                if (ptr->val >= x && ptr->next->val < x) {
                    std::swap(ptr->val, ptr->next->val); // swap values
                    swapped = true;
                }
                ptr = ptr->next;
            }
            lptr = ptr;
        } while (swapped);

        return head;
    }

    // O(n) partition using two lists
    ListNode* partition(ListNode* head, int x) {
        ListNode beforeHead(0), afterHead(0);
        ListNode* before = &beforeHead;
        ListNode* after = &afterHead;

        while (head) {
            if (head->val < x) {
                before->next = head;
                before = before->next;
            } else {
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }
        after->next = nullptr; // end list
        before->next = afterHead.next; // join two lists

        return beforeHead.next;
    }
};

// Utility function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Utility function to create a linked list from vector
ListNode* createList(vector<int> vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (int i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    Solution sol;

    vector<int> vals = {1, 4, 3, 2, 5, 2};
    ListNode* head = createList(vals);

    cout << "Original list: ";
    printList(head);

    // Bubble-style partition
    ListNode* bubbleRes = sol.partitionbubble(head, 3);
    cout << "After bubble partition (x=3): ";
    printList(bubbleRes);

    // Recreate list for clean test
    head = createList(vals);

    // O(n) partition
    ListNode* fastRes = sol.partition(head, 3);
    cout << "After O(n) partition (x=3): ";
    printList(fastRes);

    return 0;
}
