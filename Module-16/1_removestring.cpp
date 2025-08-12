#include <iostream>
#include <string>
using namespace std;
void str(string s,string t){
    if(s.length()==0)return;
    if(s[0]!='a'){
        t=t+s[s.length()-1];
        cout<<t;
    }
    
    str(s.erase(s.begin() + (s.length() -2)) ,t);
}
int main (){
    string s="apple";
    str(s,"");
    return 0;
}