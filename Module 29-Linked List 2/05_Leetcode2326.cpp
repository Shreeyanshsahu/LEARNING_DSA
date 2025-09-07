#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int maxr = m - 1;
        int maxc = n - 1;
        int count = n * m;
        vector<vector<int>> arr(m, vector<int>(n, -1)); // initialize with -1
        int minc = 0;
        int minr = 0;
        ListNode* temp = head;
        int j = 0;

        while (maxc >= minc && maxr >= minr) {
            // top row
            for (int i = minc; i <= maxc; i++) {
                if (temp != NULL) {
                    arr[minr][i] = temp->val;
                    temp = temp->next;
                }
                j++;
            }
            if (j == count) break;
            minr++;

            // right column
            for (int i = minr; i <= maxr; i++) {
                if (temp != NULL) {
                    arr[i][maxc] = temp->val;
                    temp = temp->next;
                }
                j++;
            }
            if (j == count) break;
            maxc--;

            // bottom row
            for (int i = maxc; i >= minc; i--) {
                if (temp != NULL) {
                    arr[maxr][i] = temp->val;
                    temp = temp->next;
                }
                j++;
            }
            if (j == count) break;
            maxr--;

            // left column
            for (int i = maxr; i >= minr; i--) {
                if (temp != NULL) {
                    arr[i][minc] = temp->val;
                    temp = temp->next;
                }
                j++;
            }
            minc++;
            if (j == count) break;
        }
        return arr;
    }
};

// Helper to create linked list from vector
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return NULL;
    ListNode* head = new ListNode(vals[0]);
    ListNode* temp = head;
    for (int i = 1; i < vals.size(); i++) {
        temp->next = new ListNode(vals[i]);
        temp = temp->next;
    }
    return head;
}

int main() {
    Solution sol;

    int m = 3, n = 5; // matrix size

    // create linked list from vector
    vector<int> vals = {3,0,2,6,8,1,7,9,4,2,5,5,0};
    ListNode* head = createList(vals);

    vector<vector<int>> matrix = sol.spiralMatrix(m, n, head);

    cout << "Spiral Matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
