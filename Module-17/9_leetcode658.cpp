#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int search(const vector<int> &arr, int target)
{
    int lo = 0;
    int hi = arr.size() - 1;
    int mid = 0;
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}

int lower_bound(const vector<int> &arr, int target)
{
    int lo = 0, hi = arr.size() - 1;
    int mid = 0;
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        if (arr[mid] <= target)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    return lo;
}

vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    vector<int> ans;
    int hb;
    int lb;
    int tar = search(arr,x);
    // base cases....
    if (x < arr[0])
    {
        int i = 0;
        while (k > 0)
        {
            ans.push_back(arr[i]);
            i++;
            k--;
        }
    }
    else if (x > arr[arr.size() - 1])
    {
        int i = arr.size() - 1; // Start from the last k elements
        while (k > 0)
        {
            ans.push_back(arr[i]);
            i--;
            k--;
        }
    }
    else if (k>arr.size())
    {
        int i = arr.size() - 1; // Start from the last k elements
        while (i>=0)
        {
            ans.push_back(arr[i]);
            i--;
        }
    }
    else if(tar==-1){
        hb = lower_bound(arr,x);
        lb=hb-1;
        while(k>0){
            if(lb<0){
            ans.push_back(arr[hb]);
            hb++;
            k--;
        }
        if(hb>arr.size()-1){
            ans.push_back(arr[lb]);
            lb--;
            k--;
        }
        else{
            ans.push_back(arr[lb]);
            lb--;
            k--;
            if(k<=0){
                break;
            }
            ans.push_back(arr[hb]);
            hb++;
            k--;
        }
    }
    }
    else{
        ans.push_back(arr[tar]);
        k--;
        hb = tar +1;
        lb = tar -1;
        while(k>0){
            if(lb<0){
                ans.push_back(arr[hb]);
                hb++;
                k--;
            }
            if(hb>arr.size()-1){
                ans.push_back(arr[lb]);
                lb--;
                k--;
            }
            else{
                ans.push_back(arr[lb]);
                lb--;
                k--;
                if(k==0){
                    break;
                }
                ans.push_back(arr[hb]);
                hb++;
                k--;
            }
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}

int main()
{
    vector<int> arr = {1,1,1,10,10,10};
    vector<int> ans = findClosestElements(arr, 1, 9);
    for (int i = 0; i <= ans.size() - 1; i++)
    {
        cout << ans[i] << endl;
    }
}