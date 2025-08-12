#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the length of the array"<<endl;cin>>n;
    int arr[n];
    for(int i=0; i<=n-1; i++){
        cout << "Enter element no"<<i<< ": ";
        cin >> arr[i];
    }
    cout << "Index of Element Greater than 50 aree"<<endl;
    for(int i=n-1; i>=0; i--){
        if(arr[i]>=50){
            cout << i << " ";
        }
    }
}