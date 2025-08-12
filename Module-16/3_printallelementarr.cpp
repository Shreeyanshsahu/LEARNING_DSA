#include<iostream>
using namespace std;
void print(int arr[],int index,int n){
    if(index==n){
        return;
    }
    cout<<arr[index]<<" ";
    print(arr,index+1,n);
}

int main(){
    int arr[]={1,2,3,4,5};
    print(arr,0,sizeof(arr)/sizeof(arr[0]));
    return 0;
}