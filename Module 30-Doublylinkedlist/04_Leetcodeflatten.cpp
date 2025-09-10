#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
    Node(int v) : val(v), prev(NULL), next(NULL), child(NULL) {}
};

class Solution {
public:
    Node* flattenHelp(Node* head) {
        Node* pre = head;
        while (pre->next != NULL || pre->child != NULL) {
            Node* cur = pre->next;
            if (pre->child != NULL) {
                pre->next = pre->child;
                pre->child->prev = pre;
                pre->child = NULL;

                Node* temp = flattenHelp(pre->next); // tail of child list

                if (cur != NULL) {
                    temp->next = cur;
                    cur->prev = temp;
                    pre = cur;   // continue at original next
                } else {
                    pre = temp;  // continue at child tail
                }
            } else {
                pre = pre->next;
            }
        }
        return pre;  // return tail of flattened segment
    }

    Node* flatten(Node* head) {
        if (!head) return head;
        flattenHelp(head);
        return head;
    }
};

// Helper to print flattened list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->val;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

// Build sample test case
Node* buildTestCase() {
    // 1 - 2 - 3
    //         |
    //         7 - 8
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);

    n1->next = n2; n2->prev = n1;
    n2->next = n3; n3->prev = n2;
    n3->child = n7;
    n7->next = n8; n8->prev = n7;

    return n1;
}

int main() {
    Node* head = buildTestCase();

    cout << "Original top-level list: 1 -> 2 -> 3" << endl;
    cout << "Child of 3: 7 -> 8" << endl;

    Solution s;
    Node* flat = s.flatten(head);

    cout << "\nFlattened list:" << endl;
    printList(flat);

    return 0;
}