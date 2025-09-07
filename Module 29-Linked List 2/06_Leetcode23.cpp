#include<iostream>
#include<vector>
#include<algorithm>
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* temp3 = temp1;
        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->val <= temp2->val) {
                while (temp1->next != NULL && temp1->next->val <= temp2->val)
                    temp1 = temp1->next;
                temp3 = temp1->next;
                temp1->next = temp2;
                temp1 = temp3;
            } else {
                while (temp2->next != NULL && temp2->next->val <= temp1->val)
                    temp2 = temp2->next;
                temp3 = temp2->next;
                temp2->next = temp1;
                temp2 = temp3;
            }
        }

        if (list1->val <= list2->val)
            return list1;
        else
            return list2;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;

        while (lists.size() > 1) {
            int n = lists.size();
            vector<ListNode*> mergedLists;

            for (int i = 0; i < n; i += 2) {
                ListNode* list1 = lists[i];
                ListNode* list2 = (i + 1 < n) ? lists[i + 1] : NULL;
                ListNode* merged = mergeTwoLists(list1, list2);
                mergedLists.push_back(merged);
            }

            lists = mergedLists;
        }

        return lists[0];
    }
};

// ---------- Example main (for local testing in VS Code) ----------
int main() {
    // Example: [[1,4,5],[1,3,4],[2,6]]
    ListNode* l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* l3 = new ListNode(2, new ListNode(6));

    vector<ListNode*> lists = {l1, l2, l3};

    Solution sol;
    ListNode* res = sol.mergeKLists(lists);

    // Print result
    while (res != NULL) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}
