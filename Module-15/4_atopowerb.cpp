#include<iostream>
using namespace std;
int power(int x, int y){
    if(y == 0)
    return 1;
    return x * power(x, y-1);  // Recursive call
}

int main(){
    int base, exponent;
    cout << "Enter base: ";
    cin >> base;
    cout << "Enter exponent: ";
    cin >> exponent;
    if(exponent== 0&&base==0){
        cout<<"Not defined"<<endl;
    }
    int result = power(base, exponent);
    cout << "Result: " << result << endl;
    return 0;
}