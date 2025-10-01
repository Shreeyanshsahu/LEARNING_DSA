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
void delete_even_index(queue<int>&q){
    int count = 0;
    int n = q.size();
    q.pop();
    count++;
    int t = q.front();
    while(true){
        int temp = q.front();
        q.pop();
        if(count%2!=0) q.push(temp);
        count++;
        if(count>=n) break;
    }
    cout<<endl;
}

void reverse(queue<int>&q){
    stack<int>copy;
    int t = q.front();
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        copy.push(temp);
    }
    while(!copy.empty()){
        int temp = copy.top();
        copy.pop();
        q.push(temp);
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
    reverse(q);
    display(q);
    reverse(q);
    display(q);
    delete_even_index(q);
    display(q);
    return 0;
}