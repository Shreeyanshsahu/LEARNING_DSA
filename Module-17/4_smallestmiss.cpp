#include <iostream>
#include <vector>
using namespace std;

int findSmallestMissing(vector<int>& arr) {
    int lo = 0, hi = arr.size() - 1;
    
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] - arr[0] == mid) {
            lo = mid + 1;  // Move right if sequence is continuous
        } else {
            hi = mid;  // Otherwise, missing number is on the left
        }
    }
    
    return lo + arr[0];  // Return the smallest missing number
}

int main() {
    vector<int> arr = {4, 5, 6, 8, 9, 12, 14, 15, 20}; // Smallest missing is 7
    cout << "Smallest missing number: " << findSmallestMissing(arr) << endl;
    return 0;
}
