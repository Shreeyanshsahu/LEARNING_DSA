#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include<queue>
using namespace std;

//deque insert delete both back front


void display(queue<int>&s){
    int a = s.size();
    while(a>0){
        cout<<s.front()<<endl;
        int x = s.front();
        s.pop();
        s.push(x);
        a--;
    }
}

void evendelete(queue<int>&s){
    int a = s.size();
    while(a>0){
        if(a%2!=0){
        // cout<<s.front()<<endl;
        int x = s.front();
        s.pop();
        s.push(x);}
        else{
            s.pop();
        }
        a--;
    }
}

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    // cout<< q.front()<<endl; //first in 
    // cout<<  q.back()<<endl;
    // q.pop();
    // cout<<q.front()<<endl;
    //insert at back 
    //pop at front
    // cout<<q.empty();
    display(q);
    // cout<<q.front();
    evendelete(q);
    display(q);
    return 0;
}