#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class Stack {
    Node* topNode;
    
    public:
    int size=0; // pointer to top of stack
    Stack() : topNode(NULL) {}

    // Push element onto stack
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = topNode;
        topNode = newNode;
        size++;
    }

    // Pop element from stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        size--;
    }

    // Return top element
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return topNode->data;
    }

    // Check if stack is empty
    bool isEmpty() {
        return topNode == NULL;
    }

    // Display stack contents (top → bottom)
    void display() {
        Node* temp = topNode;
        cout << "Stack: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);

    st.display();       // Stack: 30 20 10
    cout << st.top() << "\n"; // 30

    st.pop();
    st.display();  
    cout<<st.size;     // Stack: 20 10

    return 0;
}
