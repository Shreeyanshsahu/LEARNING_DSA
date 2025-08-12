#include <iostream>
#include <vector>
using namespace std;
// return the first and last occurence of the target element
vector<int> search(vector<int> &arr, int target)
{
    vector<int> ans = {-1, -1};
    int lo = 0;
    int hi = arr.size() - 1;
    int mid = 0;
    int first = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == target) {
            first = mid;  // Store position
            hi = mid - 1; // Search left for first occurrence
        } else if (arr[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    int last = -1;
    hi = arr.size() - 1;
    lo = 0;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        
        if (arr[mid] == target) {
            last = mid;  // Store position
            lo= mid + 1; // Search right for last occurrence
        } else if (arr[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    ans[0] = first;
    ans[1] = last;
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 2, 7, 3, 3, 3, 17, 29, 31};
    int target = 3;
    search(arr, target);
    vector<int> result = search(arr, target);
    cout << result[0] << " ";
    cout << result[1] << " ";
    return 0;
}