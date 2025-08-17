#include<iostream>
#include<string>
using namespace std;

int main(){
    string str ="DYIFZHZFHXEOHXXYUZ";
    string ans = "";
    for (int i = 0;i<str.length();i++){
        if(str[i]>='X'){
            ans.push_back(str[i]);
        }
    }
    cout<<ans<<endl;
    for (int i = 0;i<ans.length();i++){
        bool check = false;
        
        for (int j = 0;j<ans.length()-i-1;j++){
            if(ans[j]<=ans[j+1]){
                swap(ans[j],ans[j+1]);
                check=true;
            }
        }
        if(check==false){
            break;
        }
    }
    cout<<ans;

}