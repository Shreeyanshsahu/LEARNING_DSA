#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};


void display(Node* temp){
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int size(Node* temp){
    int count = 0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

int main() {
    Node *a = new Node(10); //new only for pointer use
    Node *b = new Node(20);
    Node *c = new Node(30);
    Node *d = new Node(40);
    a->next = b;
    b->next = c;
    c->next = d;
    display(a);
    cout<<size(a)<<endl;
    return 0;
}