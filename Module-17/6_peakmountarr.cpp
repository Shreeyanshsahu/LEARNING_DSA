#include<iostream>
using namespace std;
int peakarr(vector<int>& arr){
    int lo = 0, hi = arr.size() - 1;
    int mid;
    while (lo < hi) {
        mid = lo + (hi - lo) / 2;
        // if(lo==hi){
        //     return lo;
        // }
        if (arr[mid]>arr[mid+1]){
            hi = mid;  // Move right if sequence is continuous
        }
        else{
            lo = mid+1;  // Otherwise, missing number is on the left
        }
    }
    return lo;
}
int main(){
    vector<int> arr = {2,4,5,7,10,4,3};
    cout<<peakarr(arr);
}