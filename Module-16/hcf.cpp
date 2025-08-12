// #include<iostream>
// #include<algorithm>
// using namespace std;
// int main(){
//     int x,y;
//     cout<<"enter number1";cin>>x;
//     cout<<"enter number2";cin>>y;
//     cout<<min(x,y)<<endl;
//     int k=1;
//     for(int i=min(x,y);i>=2;i--){
//         if(x%i==0 and y%i==0){
//             k = i;
//             break; 
//         }
//     }
//     cout<<"hcf is "<<k;
// }


//Recursive soln
#include<iostream>
using namespace std;
int hcf(int m,int r){
    if(r==0){
        return m;
    }
    else{
        return hcf(r,r%m);
    }
}
int main(){
    int x,y;
    cout<<"enter number1: ";cin>>x;
    cout<<"enter number2: ";cin>>y;
    cout<<"The hcf is "<<hcf(min(x,y),max(x,y)%min(x,y));
}