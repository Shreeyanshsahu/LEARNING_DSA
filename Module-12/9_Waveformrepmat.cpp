//order should be same of 2 matrix  
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int arr1[3][3]={230,20,20,210,90,23,9,12,78};
    for(int i=0; i<3; i++){
        if(i%2==0){ 
        for(int j=0; j<3; j++){
            cout<<arr1[i][j]<<"  ";
        }}
        else{
        for(int j=2; j>=0; j--){
            cout<<arr1[i][j]<<"  ";
        }}
    }
        cout<<endl;
    }