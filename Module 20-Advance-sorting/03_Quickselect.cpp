//to find kth smallest element using quick sort

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int partition(vector<int> &nums, int start, int end)
{
    int pivt = start;
    int count = 0;
    for (int i = start+1; i <= end; i++)
    {
        if (nums[i] < nums[pivt])
        {
            count++;
        }
    }
    pivt += count;
    swap(nums[pivt], nums[start]);
    int i = start;
    int j = end;
    while (i < pivt and j > pivt)
    {
        if (nums[i] < nums[pivt])
            i++;
        else if (nums[j] > nums[pivt])
            j--;
        else
        {
            swap(nums[i], nums[j]);
            i++;j--;
        }
    }
    return pivt;
}
int kthelement(vector<int>& nums, int start, int end,int k)
{
    if (start >= end)
    {
        return nums[start];
    }
    int pivt = partition(nums, start, end);
    if(pivt+1==k){
        return nums[pivt];
    }
    else if(pivt+1>k) return kthelement(nums, start, pivt - 1,k);
    else return kthelement(nums, pivt + 1, end,k);
}

int main()
{
    vector<int> nums = {5, 1, 8, 2, 7, 6, 3, 4};
    cout<<kthelement(nums, 0, nums.size() - 1,3)<<endl;
}
