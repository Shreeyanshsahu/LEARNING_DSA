//Leetcode 39

#include <iostream>
#include<vector>
using namespace std;
void combsum(vector<int> ans,int givn[],int target,int idx){
     if(target==0){
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;
    }
    if(target<0){
        return;
    } 
    for(int i=idx;i<7;i++){
        ans.push_back(givn[i]);
        combsum(ans,givn,target-givn[i],i);
        ans.pop_back();
    }
}

int main(){
    int org[]={2,3,5,6,9,1,7};
    vector<int> ans;
    combsum(ans,org,8,0);
}