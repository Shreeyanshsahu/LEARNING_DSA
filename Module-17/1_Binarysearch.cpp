#include <iostream>
#include<vector>
using namespace std;
//binary search can be only applied on sorted array..
int search(const vector<int>& arr, int target) {
    int lo =0;
    int hi = arr.size()-1;
    int mid = 0;
    while(lo<=hi){
        mid = lo + (hi-lo)/2; // it a good method to calculate avg rather than (lo+hi)/2
        if(arr[mid]==target) return mid;
        else if(arr[mid]<target) lo = mid+1;
        else hi = mid-1;
    }
    return -1;
}
//1/2 calculation in binary search at max; than in for loop.....
int main(){
    vector<int> arr = {1, 2, 4, 7, 9, 13, 17, 29, 31};
    int target = 7;
    if(search(arr,target)<0) cout<<"Target not found in the vector";
    else cout << "The target is found at "<<search(arr, target)+1<<" postion of vector";
    return 0;
}