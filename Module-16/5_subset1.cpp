#include<iostream>
#include<string>
using namespace std;
void subset(string ans,string org){
    if(org.length()==0){
    cout<<'"'<<ans<<'"'<<"  ";   
    return;
    }
    subset(ans,org.substr(1));
    subset(ans+org[0],org.substr(1));
    }
int main(){
    string str = "abc";
    subset("",str);
    return 0;
}   