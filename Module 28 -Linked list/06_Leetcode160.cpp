#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // Method 1: Using lengths
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB) return NULL;

        int len1 = 0, len2 = 0;
        ListNode* A = headA;
        ListNode* B = headB;

        while (A) {
            len1++;
            A = A->next;
        }
        while (B) {
            len2++;
            B = B->next;
        }

        A = headA;
        B = headB;
        if (len1 > len2) {
            for (int i = 0; i < len1 - len2; i++) A = A->next;
        } else {
            for (int i = 0; i < len2 - len1; i++) B = B->next;
        }

        while (A && B) {
            if (A == B) return A;
            A = A->next;
            B = B->next;
        }
        return NULL;
    }

    // Method 2: Shorter two-pointer trick
    ListNode* getIntersectionNodeAlt(ListNode* headA, ListNode* headB) {
        if (!headA || !headB) return NULL;
        ListNode* A = headA;
        ListNode* B = headB;

        while (A != B) {
            A = (A == NULL) ? headB : A->next;
            B = (B == NULL) ? headA : B->next;
        }
        return A;
    }
};

// Helper: Print a list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create two linked lists:
    // A: 1 -> 2 -> 3 \
    //                   -> 7 -> 8 -> 9
    // B:       4 -> 5 /

    ListNode* intersect = new ListNode(7);
    intersect->next = new ListNode(8);
    intersect->next->next = new ListNode(9);

    // List A
    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = intersect;

    // List B
    ListNode* headB = new ListNode(4);
    headB->next = new ListNode(5);
    headB->next->next = intersect;

    cout << "List A: ";
    printList(headA);
    cout << "List B: ";
    printList(headB);

    Solution sol;
    ListNode* result = sol.getIntersectionNode(headA, headB);

    if (result) {
        cout << "Intersection found at node with value: " << result->val << endl;
    } else {
        cout << "No intersection found." << endl;
    }

    return 0;
}
