//Given a stock of day return the number of consecutive days stock price was greater than last drop 
// 100 80 60 81 70 60 75 85
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
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

vector<int> prevgreatest(vector<int> &arr){
    stack<int>s;

    vector<int>ans(arr.size(),1);

    s.push(0);
    int i = 1;
    while(i<arr.size()){
        // Step pop all small element indexes.
        while(!s.empty() and arr[i]>arr[s.top()])
        {
            //if the current index is greater than previous element pop the remaining indexed;
            s.pop();
        } 
        if(!s.empty()){
            // i - s.top()= sub of the index of topmost element - current element
            ans[i]=i-s.top();
        }
        else{
            // if stack empty then the current stock is greater return i +1 = current index+1
            ans[i]=i+1;
        }
        //storing the current index of element
        s.push(i);
        i++;
    }
    return ans;
}




int main() {
     vector<int> ques={100,80,60,81,70,60,75,85};
    vector<int>ans2 = prevgreatest(ques);
    for(int itr:ques){
        cout<<itr<<"  ";
    }
    cout<<endl;
    cout<<"  ";
    for(int itr:ans2){
        cout<<itr<<"   ";
    }
    return 0;

}