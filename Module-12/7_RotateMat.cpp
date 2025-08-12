#include <iostream>
#include <vector>
using namespace std;
int main(){
    int z;
    cout<<"Enter the length of the matrix: ";cin>>z;
    vector<vector<int>> mat2(z,vector<int> (z));
    int n= mat2.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<"Enter element at position ("<<i+1<<","<<j+1<<") : ";
            cin>>mat2[i][j];
        }
    }
    for(int i=0; i< n; i++){
        for(int j=0; j<n; j++){
            cout<<mat2[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    int x =0;
    for(int i=0; i<n; i++){
        for(int j=x; j<n; j++){
        if(i==j){
            continue;
        }
        else{
            int temp=mat2[i][j];
            mat2[i][j] = mat2[j][i];
            mat2[j][i] = temp;
        }
        }
        x++;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<(n/2); j++){
        int temp=mat2[i][j];
        mat2[i][j] = mat2[i][n-j-1];
        mat2[i][n-j-1] = temp;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<mat2[i][j]<<" ";
        }
        cout<<endl;
    }
    }