#include<iostream>
#include<string>
using namespace std;
void permutation(string ans,string org){
    if(org.length()==0){
    cout<<'"'<<ans<<'"'<<"  ";   
    return;
    }
    for(int i = 0;i<org.length();i++){
        string left=org.substr(0,i);
        string right=org.substr(i+1);
        permutation(ans+org[i],left+right);
    }
    }
int main(){
    string str = "abcd";
    string ans;
    permutation(ans,str);
    // cout<<str.substr(0,0);
    // cout<<str.substr(0+1);
    return 0;
}   