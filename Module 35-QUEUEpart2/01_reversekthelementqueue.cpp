#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include<queue>
using namespace std;


void display(queue<int>&q){
    int t = q.front();
    int temp = q.front();
    q.pop();
    q.push(temp);
    cout<< temp<<"  ";
    while(q.front()!=t){
        int temp = q.front();
        q.pop();
        cout<< temp<<"  ";
        q.push(temp);
    }
    cout<<endl;
}

void reverse(queue<int>&q,int k){
    stack<int>copy;
    int t = q.front();
    int s = k;
    while(k>0){
        int temp = q.front();
        q.pop();
        copy.push(temp);
        k--;
    }
    while(!copy.empty()){
        int temp = copy.top();
        copy.pop();
        q.push(temp);
    }
    while(s>0){
        int temp = q.front();
        q.pop();
        q.push(temp);
        s--;
    }
}

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    display(q);
    reverse(q,3);
    display(q);
    return 0;
}