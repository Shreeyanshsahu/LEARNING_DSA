//order should be same of 2 matrix  
#include <iostream>
#include <vector>
using namespace std;
int main(){
    // int arr[4][2]={0,0,0,0,0,0,9,9};
                    // or 
    int arr1[4][2]={{230,20},{20,210},{90,23},{9,12}};
    int arr2[4][2];
    for(int i=0; i<4; i++){
        for(int j=0; j<2; j++){
            arr2[i][j] = arr1[j][i];
        }
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<4; j++){ 
          cout<<arr2[i][j]<<"  ";
        } 
        cout<<endl;
    }
    }