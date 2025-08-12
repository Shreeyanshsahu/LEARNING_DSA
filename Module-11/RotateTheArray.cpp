#include <iostream>
#include <vector>
#include <algorithm>

//Method 1
// using namespace std;
// void Rotate(int x, vector<int>& v){
//     vector<int> temp ;
//     for(int i=v.size()-1; i>(v.size()-1)-x; i--){
//         temp.push_back(v[i]);
//     }
//     for(int i=0; i<x; i++){
//         v.pop_back();
//     }
//     for(int i=0; i<=v.size()-1; i++){
//         temp.push_back(v[i]);
//     }
//     v=temp;
// }

// int main(){
//     vector<int> v;
//     v.push_back(1);
//     v.push_back(3);
//     v.push_back(2);
//     v.push_back(4);
//     v.push_back(3);
//     v.push_back(4);
//     v.push_back(1);
//     v.push_back(6);
//     for(int i=0; i<v.size(); i++){
//         cout<<v[i]<<" ";
//     }
//     int x;
//     cout<<endl;
//     cout<<"Enter how much you want to rotate the vector"<<endl;cin>>x;
//     Rotate(x,v);
//     for(int i=0; i<v.size(); i++){
//         cout<<v[i]<<" ";
//     }
 
// }
//Method 2

using namespace std;

void Reverse(int x,int y, vector<int> &v){
    while(x<=y){
    int temp;
    temp = v[y];
    v[y]=v[x];
    v[x]=temp;
    x++;
    y--;
}}
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    v.push_back(4);
    v.push_back(3);
    v.push_back(4);
    v.push_back(1);
    v.push_back(6);
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    int x;
    cout<<endl;
    cout<<"Enter how much you want to rotate the vector"<<endl;cin>>x;
    int z = (v.size()-x)-1;
    cout<<z<<endl;
    Reverse(0,z,v);
    Reverse(0,v.size()-1,v);

    // cout<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
} 
