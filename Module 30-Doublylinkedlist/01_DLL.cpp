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
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DoubleLinkedlist
{
public:
    Node *head;
    Node *tail;
    int size;
    DoubleLinkedlist()
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
            temp->prev = tail;
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
            head->prev = temp;
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
        Node *f = head;
        for (int i = 0; i < idx - 1; i++)
        {
            t = t->next; // move to node before index
        }
        f = f->next->next;

        temp->prev = t; // link new node
        temp->next = f; // link new node
        t->next = temp;
        f->prev = temp;

        size++;
    }
    void display(Node *first, Node *last)
    {
        while (first != NULL)
        {
            cout << first->val << " ";
            first = first->next;
        }
        cout << endl;
        while (last != NULL)
        {
            cout << last->val << " ";
            last = last->prev;
        }
        cout << endl;
    }
    int length(Node *temp)
    {
        int count = 0;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    void Getelement(int idx)
    {
        if (idx < 0 or idx >= size)
        {
            cout << "Inavalid";
        }
        if (idx <= size / 2)
        {
            Node *temp = head;
            for (int i = 0; i <= idx; i++)
            {
                if (i == idx)
                    cout << temp->val << " ";
                temp = temp->next;
            }
        }
        else
        {
            Node *temp = tail;
            for (int i = size - 1; i > idx; i--)
            {
                if (i == idx)
                    cout << temp->val << " ";
                temp = temp->prev;
            }
        }
        cout << endl;
    }
    void Deleteathead()
    {
        if (size == 0)
        {
            cout << "Empty LL list" << endl;
            return;
        }
        else
        {
            Node *t = head;
            if (size == 1)
            {
                head = NULL;
            }
            t=t->next;
            t->prev=NULL;
            head=t;
        }
        size--;
    }
    void Deleteattail()
    {
        if (size == 0)
        {
            cout << "Empty LL list" << endl;
            return;
        }
        else
        {
            Node *t = tail;
            if (size == 1)
            {
                tail = NULL;
                head = NULL;
                return;
            }
            t = t->prev;
            t->next = NULL;
            tail = t;
        }
        size--;
    }
    void Delete(int idx)
    {
        if (idx < 0 or idx >= size)
        {
            cout << "Invalid index" << endl;
            return;
        }
        else if (idx == 0)
        {
            Deleteathead();
            return;
        }
        else if (idx == size - 1)
        {
            Deleteattail();
            return;
        }
        else
        {
            if (idx <= size / 2)
            {

                Node *t = head;
                int i = 0;
                while (i < idx)
                {
                    t = t->next;
                    i++;
                }
                t->prev->next = t->next;
                t->next->prev = t->prev; // it changes the next address to the next of next address
            }
            else
            {
                Node *t = tail;
                int i = size - 1;
                while (i > idx)
                {
                    t = t->prev;
                    i--;
                }
                t->prev->next = t->next;
                t->next->prev = t->prev; // it changes the next address to the next of next address
            }
            size--;
        }
    }
};

int main()
{
    DoubleLinkedlist ll;

    // Insert at end
    ll.InsertatEnd(10);
    ll.InsertatEnd(20);
    ll.InsertatEnd(30);

    // Insert at start
    ll.Insertatstart(5);

    // Insert in middle
    ll.Insert(15, 2);

    cout << "Forward & Backward Traversal:" << endl;
    ll.display(ll.head, ll.tail);

    // Get element
    cout << "Element at index 2: ";
    ll.Getelement(2);

    // Delete at head
    cout << "After deleting head:" << endl;
    ll.Deleteathead();
    ll.display(ll.head, ll.tail);

    // Delete at tail
    cout << "After deleting tail:" << endl;
    ll.Deleteattail();
    ll.display(ll.head, ll.tail);

    // Delete at index
    cout << "After deleting index 1:" << endl;
    ll.Delete(1);
    ll.display(ll.head, ll.tail);

    // Final length
    cout << "Final length = " << ll.length(ll.head) << endl;
    cout<<INT16_MIN;
    return 0;
}