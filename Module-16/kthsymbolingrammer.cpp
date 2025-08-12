#include<iostream>
using namespace std;
int kthsymbol(int n,int k){
    if(n==0){
        return 0;
    }
    if(k%2==0){
        int ans = kthsymbol(n-1,k/2);
        if(ans==0) return 1;
        else return 0;
        }
    else{
        return kthsymbol(n-1,k/2+1);
    }
}

int main(){
    cout<<kthsymbol(4,8);
}