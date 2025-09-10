#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;

        Node* temp = head;

        // 1. Interleave copies
        while (temp != NULL) {
            Node* curr = new Node(temp->val);
            curr->next = temp->next;
            temp->next = curr;
            temp = curr->next;
        }

        // 2. Assign randoms
        temp = head;
        while (temp != NULL) {
            if (temp->random)
                temp->next->random = temp->random->next;
            else
                temp->next->random = NULL;

            temp = temp->next->next;
        }

        // 3. Separate lists
        temp = head;
        Node* copy = head->next;
        Node* ans = copy;
        while (temp != NULL) {
            temp->next = temp->next->next;
            if (copy->next) copy->next = copy->next->next;
            temp = temp->next;
            copy = copy->next;
        }

        return ans;
    }
};

// ---------- Helper to print list ----------
void printList(Node* head) {
    Node* temp = head;
    unordered_map<Node*, int> idxMap;
    int idx = 0;
    for (Node* p = head; p; p = p->next) idxMap[p] = idx++;

    temp = head;
    while (temp) {
        cout << "Val: " << temp->val;
        if (temp->random)
            cout << " | Random->Index: " << idxMap[temp->random];
        else
            cout << " | Random->NULL";
        cout << endl;
        temp = temp->next;
    }
}

int main() {
    // Build a small test case: 2 nodes with randoms
    Node* n1 = new Node(7);
    Node* n2 = new Node(13);

    n1->next = n2;
    n1->random = NULL;
    n2->random = n1;

    cout << "Original list:" << endl;
    printList(n1);

    Solution s;
    Node* copied = s.copyRandomList(n1);

    cout << "\nCopied list:" << endl;
    printList(copied);

    return 0;
}
