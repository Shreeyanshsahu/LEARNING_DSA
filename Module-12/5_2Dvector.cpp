//order should be same of 2 matrix  
#include <iostream>
#include <vector>
using namespace std;
int main(){
    //for 2d vector
    vector<vector<int>> mat1;
    //row size and column size
    int row= mat1.size();
    int col= mat1[0].size();//each row stores a column
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

//transpose for vector 
//  vector<vector<int>> transpose(vector<vector<int>>& mat1) {
//     int m= mat1.size();
//     int n= mat1[0].size();//each row stores a column
//     vector<vector<int>> mat2(n,vector<int> (m));
//     for(int i=0; i<n; i++){
//         for(int j=0; j<m; j++){
//             mat2[i][j] = mat1[j][i];
//         }
//     }  
//     return mat2;
//     }