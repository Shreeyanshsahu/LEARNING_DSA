#include<iostream>
using namespace std;
void print(int arr[],int index,int n,int max){
    if(index==n){
        cout<<max<<endl;
        return;
    }
    if(max<=arr[index]) print(arr,index+1,n,arr[index]);
}

int main(){
    int arr[]={1,2,3,4,5};
    print(arr,0,sizeof(arr)/sizeof(arr[0]),arr[0]); 
    return 0;
}