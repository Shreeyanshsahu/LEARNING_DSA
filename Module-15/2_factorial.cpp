#include <iostream>
using namespace std;
int fact(int i){
    if(i>1){
    return i * fact(i-1);}
}
int main(){
    int num1;
    cout << "Enter fact numbers: ";
    cin >> num1;
    int mutl = fact(num1);
    cout << "Product: " << mutl << endl;
}