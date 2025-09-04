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




int main() {
    // explaination pointer
    // int x = 90; 
    // int *ptr = &x;
    // //(*ptr)=98;
    // cout<<*ptr;
    Node a(10);
    Node b(20);
    Node c(30);
    Node d(40);
    a.next=&b;
    b.next=&c;
    c.next=&d;
    //b==
    cout<<(*(a.next)).val<<endl;
    cout<<a.next->val<<endl;

    cout<<a.next->next->val<<endl;

    cout<<"\n\n\n";
    Node temp = a;
    

    while (1){
    cout<<temp.val<<" ";
    if(temp.next==NULL) break;
    temp = *(temp.next);
}

    return 0;
}