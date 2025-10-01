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
        cout << st.top() << "  ";
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

vector<int> Nextgreatest(vector<int> &arr){
    stack<int>s;

    vector<int>ans(arr.size(),-1);

    s.push(arr[arr.size()-1]); 
    int i = arr.size()-2;
    while(i>=0){
        // Step pop all small element.
        while(!s.empty() and arr[i]>s.top()) s.pop();
        if(!s.empty()) {
            ans[i]=s.top();
        }
        s.push(arr[i]);
        i--;
    }
    return ans;

}

vector<int> prevgreatest(vector<int> &arr){
    stack<int>s;

    vector<int>ans(arr.size(),-1);

    s.push(arr[0]);
    int i = 1;
    while(i<arr.size()){
        // Step pop all small element.
        while(!s.empty() and arr[i]>s.top()) s.pop();
        if(!s.empty()) {
            ans[i]=s.top();
        }
        s.push(arr[i]);
        i++;
    }
    return ans;

}
//time and space complexity is same as iterative


int main() {
    stack<int> st;
    vector<int> ques={3,1,2,5,4,6,2,3};
    vector<int>ans = Nextgreatest(ques);
    vector<int>ans2 = prevgreatest(ques);
    for(int itr:ques){
        cout<<itr<<"  ";
    }
    cout<<endl;
    for(int itr:ans){
        cout<<itr<<"  ";
    }
    cout<<endl;
    for(int itr:ans2){
        cout<<itr<<"  ";
    }
    return 0;
}