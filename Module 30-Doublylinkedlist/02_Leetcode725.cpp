#include <iostream>
#include <vector>
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
    int length(ListNode* temp) {
        int count = 0;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp = head;
        int n = length(head);
        int topush = n / k;
        int extra = n % k;

        // If k > n, then each list will have at most 1 node
        if (topush == 0 && k > n) {
            topush = 1;
        }

        vector<ListNode*> ans;
        while (k > 0) {
            ListNode* itr = temp;
            ListNode* itr1 = nullptr;

            // Move itr (topush - 1) steps
            for (int i = 0; i < topush - 1; i++) {
                if (itr != NULL) {
                    itr = itr->next;
                }
            }

            // Handle extra nodes
            if (extra > 0 && itr != NULL) {
                itr = itr->next;
                extra--;
            }

            // Cut the list
            if (itr != NULL) {
                itr1 = itr->next;
                itr->next = NULL;
            }

            ans.push_back(temp);
            temp = itr1;
            k--;
        }
        return ans;
    }
};

// Helper to print linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example linked list: 1->2->3->4->5->6->7->8->9->10
    ListNode* head = new ListNode(1);
    ListNode* curr = head;
    for (int i = 2; i <= 10; i++) {
        curr->next = new ListNode(i);
        curr = curr->next;
    }

    Solution sol;
    int k = 3;
    vector<ListNode*> parts = sol.splitListToParts(head, k);

    cout << "Split linked list into " << k << " parts:" << endl;
    for (int i = 0; i < parts.size(); i++) {
        cout << "Part " << i + 1 << ": ";
        printList(parts[i]);
    }

    return 0;
}
