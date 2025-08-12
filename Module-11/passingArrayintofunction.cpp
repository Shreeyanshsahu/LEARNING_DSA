#include<iostream>
using namespace std;
void function(int a[]){
    for(int i=0;i<4;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return;
}
void change(int b[]){
    b[3]=233;
}
int main(){
    int arr[4]={1,2,3,4};
    function(arr);
    change(arr);
    function(arr);
}

//Array is Pass by  reference and passed through through functions 

    //Output: 1 2 3 4
    //Output: 1 2 3 233
 //In this program, the array is passed by reference to the function change. The change function modifies the array in the main function, but the main function still sees the original array unchanged. This is because arrays are passed by reference in C++. This makes it easier to modify the values in the array from within the function.assistant

// Always pass the size of the array to the function as it will be required