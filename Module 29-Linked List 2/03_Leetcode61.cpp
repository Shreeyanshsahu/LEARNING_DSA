#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return head;
        }
        ListNode* last = head;
        ListNode* first = head;
        int count = 0;
        ListNode* temp = head; // copy, don’t touch head
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        if(k > count){
            k %= count;
        }
        if(count == k){
            return head;
        }
        while (first->next != NULL) {
            if (k <= 0)
                last = last->next;
            first = first->next;
            k--;
        }
        first->next = head;
        head = last->next;
        last->next = NULL;
        return head;
    }
};

// Utility function to print linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Utility function to create a linked list from array
ListNode* createList(int arr[], int n) {
    if (n == 0) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < n; i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    Solution sol;

    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    ListNode* head = createList(arr, n);

    cout << "Original list: ";
    printList(head);

    int k = 2;
    head = sol.rotateRight(head, k);

    cout << "Rotated list (k = " << k << "): ";
    printList(head);

    return 0;
}
