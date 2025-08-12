#include<iostream>
using namespace std;
int sqrt(int x){
    int hi = x;
    int lo = 0;
    int mid;//assume x = 121 
    int ans;
    while(lo<=hi){
        mid = lo+(hi - lo) / 2;
        if(mid*mid==x){
            return mid;
        }
        if(mid*mid>x){
            hi = mid-1;
        }
        else{
            ans = mid;
            lo = mid+1;
        }
    }
    return ans; // for the ans closet
    
}
int main(){
    int x;
    cout<<"enter the number: ";
    cin>>x;
    cout<<"the sqrt is : "<<sqrt(x);
}