#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        next = nullptr;
    }
};

int main() {
    //max heap
    priority_queue<int>maxheap;
    maxheap.push(20);
    maxheap.push(30);
    maxheap.push(-10);
    maxheap.push(99);
    maxheap.push(20);
    cout<<maxheap.top()<<endl;
    priority_queue< int, vector<int> ,greater<int> >minheap;
    minheap.push(20);
    minheap.push(30);
    minheap.push(-10);
    minheap.push(99);
    minheap.push(20);
    cout<<minheap.top()<<endl;
    return 0;
}