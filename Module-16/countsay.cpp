#include<iostream>
#include<string>
using namespace std;
string countAndSay(int n) {
      if(n==1) return "1";
      else{
      string str =   countAndSay(n-1);
      int freq =1 ;
      string temp="";
      for(int i = 1;i<=str.length();i++){
        if(str[i]!=str[i-1]){
         temp+=to_string(freq)+str[i-1];
            freq=1;
        }
        else{
            freq++;
        }
      }
      return temp;
      }
}

int main(){
    cout<<countAndSay(3);
    return 0;
}

