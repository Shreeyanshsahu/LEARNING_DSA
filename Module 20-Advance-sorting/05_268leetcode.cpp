#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int missingNumber(vector<int> nums) {
        int sum = 0;
        int actual_sum = 0;
        int i = 0;
        while(i<nums.size()){
            sum+=nums[i];
            actual_sum +=(i+1);
            i++;
        }
        return actual_sum-sum;
    }
int cyclesort_method(vector<int>& nums){
    int i = 0;
    while(i < nums.size()){
        if(nums[i] < nums.size() && nums[i] != i){
            swap(nums[i], nums[nums[i]]);
        } else {
            i++;
        }
    }

    for (int i = 0; i < nums.size(); i++){
        if(i != nums[i]){
            return i; // missing number
        }
    }
    return nums.size(); 
}
int main(){
    vector<int> nums = {0, 5, 1, 8, 7, 6, 3, 4};
    cout<< missingNumber(nums) << endl;
    cout<<cyclesort_method(nums);
}