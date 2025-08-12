#include<iostream>
#include<string>
#include<vector>
using namespace std;
void subset(vector<int> ans,vector<int> org,int y,int k){
    if(y==org.size()){
        if(ans.size()==k){
        cout<<"{ ";
        for(int i =0;i<ans.size();i++){
         cout<<ans[i]<<" ";
        }
        cout<<"}"<<endl;}
    return;
    }
    subset(ans,org,y+1,k);
    ans.push_back(org[y]);
    subset(ans,org,y+1,k);
    }
int main(){
    vector<int> ans;
    vector<int> org;
    for(int i =1;i<=5;i++){
         org.push_back(i);
        }
    int k;cout<<"enter length of subseq";
    cin>>k;
    subset(ans,org,0,k);
    return 0;
}   