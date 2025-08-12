#include <iostream>
#include <vector>
using namespace std;
int main(){
    // int arr[4][2]={0,0,0,0,0,0,9,9};
                    // or 
    int arr[4][2]={{230,20},{20,210},{90,23},{9,12}};
    int max=INT16_MIN;
    for(int i=0; i<4; i++){
        for(int j=0; j<2; j++){
            if(arr[i][j]>max){
                max=arr[i][j];
            }
        }
    }
    int sum=0;
    for(int i=0; i<4; i++){
        for(int j=0; j<2; j++){
            sum+=arr[i][j];
        }
        cout<<endl;
    }
    cout<<"Maximum value: "<<max<<endl;
    cout<<"Sum value: "<<sum<<endl;
    return 0;
    }