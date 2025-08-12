#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
vector<int> removeDuplicates(vector<int>& nums) {
         int slow = 0;
    for (int fast = 1; fast < nums.size(); fast++) {
        if (nums[fast] != nums[slow]) {
            slow++;
            nums[slow] = nums[fast];
        }
    }
    return nums;
    }
int main() {
    vector<int> v = {0,0,1,1,1,2,2,3,3,4};
   removeDuplicates(v);
   for (int i = 0;i<v.size();i++){
    cout<<v[i]<<" ";
   }
}
