#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main(){
    vector<int> nums = {5, 1, 8, 2, 7, 6, 3, 4};
    int i = 0;
    while(i<nums.size()){
        if(nums[i]==i+1) i++;
        else swap(nums[i],nums[nums[i]-1]);
    }
    for (int itr : nums)
    {
        cout << itr << " ";
    }
}