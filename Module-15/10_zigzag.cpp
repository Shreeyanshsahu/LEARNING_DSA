#include<iostream>
using namespace std;
void preinpost(int x){
    if (x==0) return;
    cout <<"  " << x;
    preinpost(x-1);
    cout <<"  " << x;
    preinpost(x-1);
    cout <<"  " << x;
    preinpost(x-1);
}

int main(){
    preinpost(3);
}