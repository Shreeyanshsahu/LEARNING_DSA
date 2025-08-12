#include<iostream>
using namespace std;
int pow(int x, int y){
    if (y<=1){
        return x;
    }
    return pow(x,y/2) * pow(x, y/2);
}

int main(){
    cout<<pow(3,5);
}