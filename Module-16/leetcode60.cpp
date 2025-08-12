#include<iostream>
using namespace std;
int facto(int n){
    if(n<=0) return 1;
    return n*facto(n-1);
}
string helper(string str, string ans, int k,int ind,int x) {
        int n = str.length();
        int fact = facto(n);
        int temp = facto(n-1);
        for (int i = 0; i<=fact; i+=temp) {
            if(i>=k){ind = i; break;}
        }
        if(n==1){
            ans+=str[0];
        }
        else ans+=str[ind/temp-1];
        string left =str.substr(0,ind/temp-1);;
        string right = str.substr(ind/temp);
        str=left+right;
        int temp2 ;
        if(k%fact==0)temp2= temp;
        else temp2 = k-temp;
        if(ans.length()==x) return ans;
        else return helper(str,ans,temp2,0,x);
    }

int main(){
    string str = "";
    int n = 4;
        for (int i = 1; i <= n; i++) {
            str += to_string(i);
        }
    int k = 9;
    string ans = helper(str,"",k,0,n);
    cout<<ans;
}    