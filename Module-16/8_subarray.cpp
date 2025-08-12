// #include<iostream>
// #include<array>
// using namespace std;
// int main(){
//     int arr[]={1,2,3,4};
//     int l=sizeof(arr)/sizeof(arr[0]);
//     for(int i=1;i<=l;i++){
//         for(int k=1;k<=l-i+1;k++){
//             for(int j=i;j<=l-k+1;j++ ){
//                 cout<<j<<" ";
//             }
//         cout<<endl;
//         }
//     }
// }
#include<iostream>
#include<string>
#include<vector>
using namespace std;
void subset(vector<int> ans,vector<int> org,int y){
    if(y==org.size()){
        cout<<"{ ";
        for(int i =0;i<ans.size();i++){
         cout<<ans[i]<<" ";
        } 
        cout<<"}"<<endl;
    return;
    }

    subset(ans,org,y+1);

    if(ans.size()==0||ans[ans.size()-1]==org[y-1]){
    ans.push_back(org[y]);
    subset(ans,org,y+1);}

    }
    
int main(){
    vector<int> ans;
    vector<int> org;
    for(int i =1;i<=4;i++){
         org.push_back(i);
        }
    subset(ans,org,0);
    return 0;
}   