#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
void veiwstack(stack<int>& st)
{
    stack<int> temp;
    while (!st.empty())
    {
        cout << st.top() << endl;
        temp.push(st.top());
        st.pop();
    }
    while (!temp.empty())
    {
        st.push(temp.top());
        temp.pop();
    }
}

void recursivestack(stack<int> &st){
    if(!st.empty()){
        return;
    }
    cout<<st.top()<<endl;
    int x = st.top();
    st.pop();
    recursivestack(st);
    st.push(x);
}

void recursivepushatbottom(stack<int> &st,int val,int idx){
    if(idx==1){
        st.push(val);
        return;
    }
    // cout<<st.top()<<endl;
    int x = st.top();
    st.pop();
    recursivepushatbottom(st,val,idx-1);
    st.push(x);
}

//time and space complexity is same as iterative


int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    veiwstack(st);
    recursivestack(st);
    cout<<endl;
    veiwstack(st);
    cout<<endl;

    recursivepushatbottom(st,59,3);
    veiwstack(st);
    return 0;
}