//order should be same of 2 matrix  
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int m,n,q;
    cout<<"Enter the number of rows for the first matrix: ";
    cin>>m;
    cout<<"Enter the number of  columns for the 1st matrix and rows for 2nd matrix: ";
    cin>>n;
    cout<<"Enter the number columns for the second matrix: ";
    cin>>q;
    vector<vector<int>> mat1(m,vector<int>(n));
    vector<vector<int>> mat2(n,vector<int>(q));
    vector<vector<int>> mat3(m,vector<int>(q));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<"Enter element at position ("<<(i+1)<<","<<(j+1)<<") : ";
            cin>>mat1[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<q; j++){
            cout<<"Enter element at position ("<<(i+1)<<","<<(j+1)<<") : ";
            cin>>mat2[i][j];
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){ 
          cout<<mat1[i][j]<<"  ";
        } 
        cout<<endl;
    }
    cout<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<q; j++){ 
          cout<<mat2[i][j]<<"  ";
        } 
        cout<<endl;
    }
    cout<<endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<q; j++){
            int temp = 0;
            for(int k=0; k<n; k++){
                temp += mat1[i][k]*mat2[k][j];
            }
            mat3[i][j] = temp;
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<q; j++){ 
          cout<<mat3[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;
}