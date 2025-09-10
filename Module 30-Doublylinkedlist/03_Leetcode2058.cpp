#include <iostream>
#include <vector>
#include <climits> // for INT_MIN, INT_MAX
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return {-1, -1};

        vector<int> critpts;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int idx = 1; // position of curr

        while (curr->next != NULL) {
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {
                critpts.push_back(idx);
            }
            prev = curr;
            curr = curr->next;
            idx++;
        }

        if (critpts.size() < 2) return {-1, -1};

        int minimum = INT_MAX;
        for (int i = 1; i < critpts.size(); i++) {
            minimum = min(minimum, critpts[i] - critpts[i - 1]);
        }

        int maximum = critpts.back() - critpts.front();

        return {minimum, maximum};
    }
};

// Helper function to build linked list from vector
ListNode* buildList(const vector<int>& vals) {
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
    int n, k;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> vals(n);
    cout << "Enter linked list values: ";
    for (int i = 0; i < n; i++) cin >> vals[i];

    ListNode* head = buildList(vals);
    Solution sol;
    vector<int> result = sol.nodesBetweenCriticalPoints(head);

    cout << "Minimum distance: " << result[0] << endl;
    cout << "Maximum distance: " << result[1] << endl;

    return 0;
}
