// return the number which is greater than or equal to the target
#include <iostream>
#include<vector>
using namespace std;

int lower_bound(const vector<int>& arr, int target) {
    int lo = 0, hi = arr.size() - 1;
    int mid = 0;
    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;
        
        if (arr[mid] <=target) {
            lo = mid+1;
        } else {
            hi = mid - 1;
        }
    }
    return lo;
}

int main() {
    vector<int> arr = {1,1,1,10,10,10};
    int target = 9;
    int ans= lower_bound(arr, target);
    if(ans<arr.size())cout << "The closest lower number from the number: "<< arr[ans]<<" at positon "<<ans;
    else cout<<"Target out of bound";
    return 0;
}