#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

void veiwstack(stack<int> st)
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
void reverstack(stack<int>& st)
{
    stack<int> temp;
    while (!st.empty())
    {
        cout << st.top() << endl;
        temp.push(st.top());
        st.pop();
    }
    cout<<endl;
    stack<int>temp2;
    while (!temp.empty())
    {
        temp2.push(temp.top());
        temp.pop();
    }
    while (!temp2.empty())
    {
        st.push(temp2.top());
        temp2.pop();
    }

}
void putBottom(stack<int>& st,int val)
{
    stack<int>temp2;
    while (!st.empty())
    {
        // cout << st.top() << endl;
        temp2.push(st.top());
        st.pop();
    }
    cout<<endl;
    
    st.push(val);
    while (!temp2.empty())
    {
        st.push(temp2.top());
        temp2.pop();
    }

}
int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    veiwstack(st);
    // cout<<endl;
    cout<<"\n \n";
    reverstack(st);
    veiwstack(st);
    putBottom(st,90);
    veiwstack(st);
    return 0;
}