#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include<queue>
#include <algorithm>
using namespace std;

vector<int> firstneg(vector<int>&v,int k){
    queue<int> negidx;
    int i = 0;
    while (i<v.size())
    {
        if(v[i]<0){
            negidx.push(i);
        }
        i++;
    }
    vector<int>ans(v.size()-k+1,0);
    i = 0;
    while (i<v.size()-k+1)
    {
        if(negidx.front()<i){
            negidx.pop();
        }
        if(negidx.front()<i+k and negidx.front()>=i){
            ans[i]=v[negidx.front()];
        }
        i++;
    }
    return ans;
}




int main() {
    vector<int> v = {0,-1,-2,3,4,-5,6,4,7,-8};
    vector<int>ans = firstneg(v,3);
    for(int i =0;i<ans.size();i++){
        cout<<ans[i]<<"  ";
    }
    return 0;
}