#include<iostream>
using namespace std;
int add(int i, int b){
    return i + b;
}
int subtract(int i, int b){
    return i - b;
}
int multiply(int i, int b){
    return i * b;
}
int main(){
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    int sum = add(num1, num2);
    int subt = subtract(num1, num2);
    int mutl = multiply(num1, num2);
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << subt << endl;
    cout << "Product: " << mutl << endl;
}