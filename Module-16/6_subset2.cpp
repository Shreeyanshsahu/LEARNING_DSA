#include<iostream>
#include<string>
using namespace std;
void subset(string ans,string org,bool flag){
    if(org.length()==0 and flag==true){
    cout<<'"'<<ans<<'"'<<"  ";   
    return;}
    if(org[0]==org[1]){
        if(flag==true)
    subset(ans,org.substr(1),true);
    subset(ans+org[0],org.substr(1),false);
    }
    else{
        if(flag==true)
    subset(ans,org.substr(1),true);
    subset(ans+org[0],org.substr(1),true);
    }
}
int main(){
    string str = "aac";
    subset("",str,true);
    return 0;
}   