//Leetcode 33

#include <iostream>
using namespace std;
// 21,24,41,59,0,1,3,4,9,10   59 pivt
// 21 2 20  21 pivt


int binary(const vector<int>& arr, int target,int lo,int hi){
    int mid = 0;
    while(lo<=hi){
        mid = lo + (hi-lo)/2; // it a good method to calculate avg rather than (lo+hi)/2
        if(arr[mid]==target) return mid;
        else if(arr[mid]<target) lo = mid+1;
        else hi = mid-1;
    }
    return -1;
}

int pivt(vector<int> &nums)
{
    int lo = 0;
    int hi = nums.size() - 1;
    int mid = -1;
    if (nums.size() <= 1 or nums[lo] < nums[hi])
        return -1;
    else
    {
        while (lo < hi)
        {
            mid = lo + (hi - lo) / 2;
            if (mid <hi && nums[mid] > nums[mid + 1])
                return mid;
            if (mid >lo && nums[mid] < nums[mid - 1])
                return mid - 1;
            if(nums[lo]==nums[mid]){
                hi = mid-1;
            }
            if (nums[lo] < nums[mid])
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid-1;
            }
        }
        return -1;
    }
}

int search(vector<int> &nums, int target)
{
    int pivot = pivt(nums);
    if (pivot != -1)
    {
        if (target <= nums[pivot] && target>=nums[0])
        {
            return binary(nums,target,0,pivot);
        }
        else{
            return binary(nums,target,pivot+1,nums.size()-1);
        }
    }
    else
    {
        return binary(nums,target,0,nums.size()-1);
    }
    return -1;
}

int main()
{
    vector<int> nums = {1,0,1,1,1};
    int target;
    cout << "Enter a number ";
    cout<<pivt(nums);
    cin >> target;
    cout << search(nums, target);
    return 0;
}