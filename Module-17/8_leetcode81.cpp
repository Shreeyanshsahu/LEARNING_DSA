#include <iostream>
using namespace std;
bool binary(const vector<int>& arr, int target, int lo, int hi) {
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == target)
            return true;
        else if (arr[mid] < target)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return false;
}

int pivt(vector<int>& nums) {
    int lo = 0, hi = nums.size() - 1;
    if (nums.size() <= 1 || nums[lo] < nums[hi]) 
        return -1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (mid < hi && nums[mid] > nums[mid + 1])
            return mid;
        if (mid > lo && nums[mid] < nums[mid - 1])
            return mid - 1;

        // Handling duplicates
        if (nums[lo] == nums[mid] && nums[mid] == nums[hi]) {
            if (lo < hi && nums[lo] > nums[lo + 1])
                return lo;
            ++lo;
            if (hi > lo && nums[hi] < nums[hi - 1])
                return hi - 1;
            --hi;
        }
        else if (nums[lo] <= nums[mid]) {
            lo = mid + 1;
        } 
        else {
            hi = mid - 1;
        }
    }
    return -1;
}

bool search(vector<int>& nums, int target) {
    int pivot = pivt(nums);
    if (pivot != -1) {
        if (target >= nums[0]) {
            return binary(nums, target, 0, pivot);
        } else {
            return binary(nums, target, pivot + 1, nums.size() - 1);
        }
    }
    return binary(nums, target, 0, nums.size() - 1);
}
int main()
{
    vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1};
    int target;
    cout << "Enter a number ";
    // cout<<pivt(nums);
    cin >> target;
    cout << search(nums, target);
    return 0;
}