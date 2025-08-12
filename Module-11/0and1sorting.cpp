#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void swap(vector<int>& v){
    int i = 0;
    int j = v.size()-1;
    while(i<j){
        if(v[i] ==0){
            i++;
        }
        if(v[j] ==1){
            j--;
        }
        if(v[i] ==1 and v[j]==0){
            v[i] = 0;
            v[j] = 1;
        }
    }
}
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(0);
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
    v.push_back(0);
    v.push_back(1);
    // v.at(0) = 12;
    for (int i = 0; i<v.size(); i++)
    {
        cout << v[i] << " ";
    }
    swap(v);
    cout<<endl;
    for (int i = 0; i<v.size(); i++)
    {
        cout << v[i] << " ";
    }
// int main(){
//     vector<int> v;
//     v.push_back(1);
//     v.push_back(0);
//     v.push_back(0);
//     v.push_back(1);
//     v.push_back(1);
//     v.push_back(0);
//     v.push_back(0);
//     v.push_back(1);
//     v.push_back(1);
//     v.push_back(0);
//     v.push_back(0);
//     v.push_back(1);
//     v.push_back(1);
//     v.push_back(0);
//     v.push_back(0);
//     v.push_back(1);
//     // v.at(0) = 12;
//     for (int i = 0; i<v.size(); i++)
//     {
//         cout << v[i] << " ";
//     }
//     int z=0;
//     int p=0;
//     for (int i = 0; i<v.size(); i++)
//     {
//         if(v[i]==1)z++;
//         else if(v[i]==0)p++;
//         else continue;
//     }
//     cout<<endl;
//     cout<<p;
//     cout<<z;
//     for (int i = 0; i<v.size(); i++)
//     {
//         if(i<p)
//         v[i]=0;
//         if(i>=p)
//         v[i]=1;
//         else continue;
//     }
//     cout<<endl;
//     for (int i = 0; i<v.size(); i++)
//     {
//         cout << v[i] << " ";
//     }
    
// }