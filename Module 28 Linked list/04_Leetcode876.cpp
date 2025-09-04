#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * LinkedList class for easier handling
 */
class LinkedList {
public:
    ListNode* head;

    LinkedList() : head(nullptr) {}

    // Insert node at end
    void insert(int val) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        ListNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    // Print entire linked list
    void print() {
        ListNode* temp = head;
        while (temp) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

/**
 * Solution class for finding middle node
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast->next != NULL) return slow->next; // even length case
        return slow; // odd length case
    }
};

// --- Driver code ---
int main() {
    // Odd length list: 1 -> 2 -> 3 -> 4 -> 5
    LinkedList oddList;
    for (int i = 1; i <= 5; i++) oddList.insert(i);

    cout << "Odd length linked list: ";
    oddList.print();

    Solution s;
    ListNode* middleOdd = s.middleNode(oddList.head);
    cout << "Middle of odd list: " << middleOdd->val << endl << endl;

    // Even length list: 10 -> 20 -> 30 -> 40 -> 50 -> 60
    LinkedList evenList;
    for (int i = 1; i <= 6; i++) evenList.insert(i * 10);

    cout << "Even length linked list: ";
    evenList.print();

    ListNode* middleEven = s.middleNode(evenList.head);
    cout << "Middle of even list: " << middleEven->val << endl;

    return 0;
}
