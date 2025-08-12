//not fixed size like array 
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cout<<"enter length of vector  ";cin>>n;
    vector<int>v; // fixed size vector
    for(int i = 0; i < n; i++){
        int x;
        cout<<"enter element at "<<i<<" index  ";cin>>x;
        v.push_back(x);
    }
    for(int i = 0; i < n; i++){
        cout<<v[i]<<" ";
    }
//     vector<int> v(5);
//     cout<<v[3]<<endl; //output   0

//     vector<int> s(5,123);
//     cout<<s[3]; //output   123 for all index 

}  