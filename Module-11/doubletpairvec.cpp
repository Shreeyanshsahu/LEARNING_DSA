#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Doublet Pairing
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
//     int x = 7;
//     // v.at(0) = 12;
//     for (int i = 0; i<=v.size()-2; i++)//-2 for i not repeating the same doublet 
//     {
//         for(int j = v.size()-1; j>=0; j--){
//             if(v[j]+v[i] == x){
//                 cout<<'('<<i<<','<<j<<')'<<endl;
//             }
//         }
//     }
// }

//reverse vector in new vector
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
//     vector<int> v2(v.size());
//     for (int i = v.size()-1; i>=0; i--)//-2 for i not repeating the same doublet 
//     {
//         v2[i]=v[v.size()-i-1];
//     }
//     for(int i=0; i<v2.size(); i++){
//         cout<<v[i]<<" ";
//     }
//     cout<<endl;
//     for(int i=0; i<v2.size(); i++){
//         cout<<v2[i]<<" ";
//     }
//     return 0;
 
// }

//reverse in same vector
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
//     // vector<int> v2(v.size());
//     for(int i=0; i<v.size(); i++){
//         cout<<v[i]<<" ";
//     }
//     cout<<endl;
//     int k = 0;
//     for (int i = v.size()-1; i>=(v.size()/2); i--)//-2 for i not repeating the same doublet 
//     {
//         int temp;
//         temp=v[i];
//         v[i]=v[k];
//         v[k]=temp;
//         k++;
//     }
//     for(int i=0; i<v.size(); i++){
//         cout<<v[i]<<" ";
//     }
//     return 0;
 
// }
//inbuilt
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
    // vector<int> v2(v.size());
    reverse(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
 
}