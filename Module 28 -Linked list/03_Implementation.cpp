#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
class Linkedlist
{
public:
    Node *head;
    Node *tail;
    int size;
    Linkedlist()
    {
        head = tail = NULL;
        size = 0;
    }
    void InsertatEnd(int ele)
    {
        Node *temp = new Node(ele);
        if (size == 0)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    void Insertatstart(int ele)
    {
        Node *temp = new Node(ele);
        if (size == 0)
        {
            head = tail = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
        size++;
    }
    void Insert(int ele, int idx)
    {
        Node *temp = new Node(ele);
        if (idx > size)
        {
            cout << "invalid index";
            return;
        }
        if (idx == 0)
        {
            Insertatstart(ele);
            return;
        }
        else if (idx == size)
        {
            InsertatEnd(ele);
            return;
        }
        
        Node *t = head;
        for (int i = 0; i < idx - 1; i++)
        {
            t = t->next; // move to node before index
        }

        temp->next = t->next; // link new node
        t->next = temp;

        size++;
    }
    void display(Node *temp)
    {
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    int length(Node *temp){
        int count = 0;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    void Getelement(int idx){
        Node *temp = head;
        if(idx <0 or idx>=size){
            cout<<"Inavalid";
        }

        for(int i =0;i<=idx;i++)
        {
            if(i==idx) cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void Deleteathead(){
        if (size == 0)
        {
            cout<<"Empty LL list"<<endl;
            return;
        }
        else
        {
            if(size==1){
                tail=NULL;
            }
            head = head->next;
        }
        size--;
    }
    void Deleteattail(){
        if (size == 0)
        {
            cout<<"Empty LL list"<<endl;
            return;
        }
        else
        {
        Node *t = head;
        while(t->next!=tail)
        {
            t = t->next;
        }
        t->next=NULL;
        tail=t;
        }
        size--;
    }
    void Delete(int idx){
        if(idx<0 or idx>=size){
            cout<<"Invalid index"<<endl;
            return;
        }
        else if(idx==0){
            Deleteathead();
            return;
        }
        else if(idx==size-1){
            Deleteattail();
            return;
        }
        else{
            Node*t = head;
            int i = 0;
            while (i<idx)
            {
                t=t->next;
                i++;
            }
            t->next=t->next->next;//it changes the next address to the next of next address 
            size--;
        }
    }
};

int main()
{
    Linkedlist ll;
    ll.InsertatEnd(10);
    ll.InsertatEnd(20);
    ll.display(ll.head);
    ll.Insertatstart(0);
    ll.display(ll.head);
    ll.Insert(90,3);
    ll.display(ll.head);
    cout << ll.size << endl;
    ll.Getelement(3);
    ll.display(ll.head);
    // ll.Deleteathead();
    // ll.display(ll.head);
    // ll.Deleteattail();
    // ll.display(ll.head);
    ll.Delete(2);
    ll.display(ll.head);
    // return 0;
}