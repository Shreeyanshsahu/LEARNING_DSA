#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
struct Node
{
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        next = nullptr;
    }
};


void interleave(queue<int>&q)
{
    int half = q.size() / 2;
    stack<int> st;

    // Step 1: push first half into stack
    for (int i = 0; i < half; i++) {
        st.push(q.front());
        q.pop();
    }

    // Step 2: enqueue back stack elements (reversed first half)
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    // Step 3: move first half (which is reversed second half) to back
    for (int i = 0; i < half; i++) {
        q.push(q.front());
        q.pop();
    }

    // Step 4: push first half (original order restored) into stack
    for (int i = 0; i < half; i++) {
        st.push(q.front());
        q.pop();
    }

    // Step 5: interleave stack and queue
    while (!st.empty()) {
        q.push(st.top()); st.pop();   // one from stack (first half)
        q.push(q.front()); q.pop();   // one from queue (second half)
    }
}
void displayQueue(queue<int> q) {  // pass by value so original queue is not modified
    cout << "Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return;
}

int main()
{
    // Make a queue of 1 2 3 4 5 6 7 8
    // 1 5 2 6 3 7 4 8
    //  but only using one stack
    queue<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    interleave(s);
    displayQueue(s);
    return 0;
}