#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//Method 1 Brute Force //24 opreations
//space efficiency but time deffecinecy 
// int main(){
//     int arr[] = {6,3,2,4,1,7,1,5};
//     int sort;
//     bool rr=false;
//     for(int i=0; i<7; i++){
//         for(int j=i+1; j<8; j++){
//                 if(arr[j]==arr[i]){
//                     sort = arr[j];
//                     break;
//                     rr=true;
//                 }
//         }
//         if(rr==true){
//             break;
//         }
//     }
//     cout<<"Duplicate element is: "<<sort;
//     return 0;
// }

//Method 2 0 and 1 
// time effecicent but space defficient
// int main(){
//     vector<int>a = {6,3,2,4,1,7,1,5};
//     int max_element = a[0];
//     for (int i = 0; i< a.size(); i++) {
//     if (a[i] > max_element){
//         max_element = a[i];
//     }
//     }
//     cout << max_element << endl;
//     vector <int>neew;
//     for (int i = 0; i<max_element+1; i++) {
//     neew.push_back(0);
//     }
//     for(int i=0; i<a.size();i++){
//         if(neew[a[i]]==0){
//         neew[a[i]]=1;}
//         else{
//             cout<<"Duplicate element is: "<<a[i];
//             break;
//         }
//     }
//     return 0;
// }

//Method 3 both time and space efficient using maths 
int main(){
    vector<int>a = {6,3,2,4,1,7,1,5};
    int max_element = a[0];
    for (int i = 0; i< a.size(); i++) {
    if (a[i] > max_element){
        max_element = a[i];
    }
    }
    cout << max_element << endl;
    vector <int>neew;
    for (int i = 0; i<max_element+1; i++) {
    neew.push_back(0);
    }
    for(int i=0; i<a.size();i++){
        if(neew[a[i]]==0){
        neew[a[i]]=1;}
        else{
            cout<<"Duplicate element is: "<<a[i];
            break;
        }
    }
    return 0;
}