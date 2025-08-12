#include<iostream>
using namespace std;
int print(int n){
    if(n == 0) return 0;
    cout << n <<endl;
    return print(n-1);
}
int print2(int i,int n){
    if(i > n) return 0;
    cout << i << " ";
    return print2(i+1,n);
}
int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "The Fibonacci series up to " << n << " is: "<<endl;
    print(n);
    cout << "The Fibonacci series up to " << n << " is: "<<endl;
    print2(1,n);
    return 0;
}
