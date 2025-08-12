#include<iostream>
using namespace std;
void hanoi(int n,char a,char b,char c){
    if(n==0) return;
    hanoi(n-1,a,c,b);
    cout<<"Move disk "<<n<<" from pole "<<a<<" to pole "<<c<<endl;
    hanoi(n-1,b,a,c);
}

int main(){
    int n;
    cout<<"Enter the number of disks: ";
    cin>>n;
    hanoi(n,'A','B','C');
    return 0;  // return 0 to indicate successful termination of the program
}