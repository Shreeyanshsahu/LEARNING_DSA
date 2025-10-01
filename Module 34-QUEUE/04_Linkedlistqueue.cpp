#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int length = 0;
struct Node
{
    int val = 0;
    Node *next;
    Node(int val){
        this->val=val;
        next=NULL;
    }
};
Node* head = nullptr;
Node* tail = nullptr;

void push(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = tail=newNode;
    } 
    else {
        tail->next = newNode;
        tail=tail->next;
        tail->next=nullptr;
    }
    length++;
}

void pop() {
    if (head == nullptr) {
        cout<<"Queue empty"<<endl;
    } 
    else {
        Node *temp = head;
        while(temp->next!=tail) temp = temp->next;
        temp->next=nullptr;
        delete tail;
        tail=temp;
    }
    length--;
}

// Function to display the linked list
void display() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << "\n";
}




int main() {
    push(23);
    push(23);
    push(23);
    push(3);
    display();
    pop();
    display();
    return 0;
}