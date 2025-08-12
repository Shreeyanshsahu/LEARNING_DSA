//binary str without consecutive 1
#include<iostream>
#include<vector>
using namespace std;
void binary(vector<int>&ans,int n){
    if(ans.size()==n){
        cout<<"{ ";
        for(int i =0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<"} "<<endl;
        return;
    }
        ans.push_back(0);
        binary(ans,n);
        ans.pop_back();
        if(ans.back()!=1 or ans.empty()){
            ans.push_back(1);
            binary(ans,n);
            ans.pop_back();
            }
            
}
int main(){
    vector <int>ans;
    binary(ans,4);
}