#include<iostream>
// n = no of stair ..
// s = sum + 1 if  n ==0 

using namespace std;
int stair(int s,int n){
    if(n<0) return s=0;
    if(n==0) return s=+1;
    return stair(s,n-1) + stair(s,n-2);
}

int main(){
    cout<<stair(0,4);
}