//1,1,2,3,5,8,13,21--------

#include<iostream>
using namespace std;

int fibonacci(int n){
    if(n==1 or n==2)
        return 1;
    else 
    return fibonacci(n-1)+fibonacci(n-2);
}

int main(){
    int n;
    cout<<"Enter the number of terms: ";
    cin>>n;
    cout<<"Fibonacci series: ";
    cout<<fibonacci(n)<<" ";
    return 0;
}