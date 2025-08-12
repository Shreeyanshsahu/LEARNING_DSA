//Declarations 
#include <iostream>
#include <vector>
using namespace std;
int main(){
    // int arr[4][2]={0,0,0,0,0,0,9,9};
                    // or 
    int arr[4][2]={{0,0},{0,0},{0,0},{9,9}};
                    //or
    // 4 rows and 2 columns
    // for(int i=0; i<4; i++){
    //     for(int j=0; j<2; j++){
    //         cout<<"Enter element at position ("<<i<<","<<j<<") : ";
    //         cin>>arr[i][j];
    //     }
    // }
    for(int i=0; i<4; i++){
        for(int j=0; j<2; j++){
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }
}
//filling the columns is necessary
//int arr[][2]={68,2,2,33,,4,44,2,1}; will work also