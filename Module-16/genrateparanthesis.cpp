#include<iostream>
#include<vector>
using namespace std;
void paranthesis(string ans,int open,int end,int n,vector<string> &final){
    if(end==n){
        final.push_back(ans);
        return;
    }
    if(open<n){ 
    paranthesis(ans+"(",open+1,end,n,final);
    }
    if(end<open)
    paranthesis(ans+")",open,end+1,n,final);
}
int main(){
    int n;
    cout<<"Enter number of paranthesis genrator: ";
    cin>>n;
    vector<string> final;
    paranthesis("",0,0,n,final);
    for(int i =0;i<final.size();i++){
        cout<<final[i]<<endl;
    }
}