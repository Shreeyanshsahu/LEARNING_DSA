//mom dad
#include<iostream>
#include<string>
using namespace std;
bool palindrom(string s){
    int f = 0;
    int e = s.length()-1;
    while(f<e){
        if(s[f]!=s[e]) return false;
        f++; 
        e--;
    }
    return true;
}
int main(){
    string s = "moom";
    if(palindrom(s)==1) cout<<"palindrom";
    if(palindrom(s)==0) cout<<"notpalindrom";
}