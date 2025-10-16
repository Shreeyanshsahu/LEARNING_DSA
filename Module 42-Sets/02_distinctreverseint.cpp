#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // Function to reverse digits of an integer
    int reverse(int x) {
        int ans = 0;
        while (x > 0) {
            ans = ans * 10 + (x % 10);
            x /= 10;
        }
        return ans;
    }

    // Function to count distinct integers and their reverses
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> set;
        for (int i = 0; i < nums.size(); i++) {
            set.insert(nums[i]);
            set.insert(reverse(nums[i]));
        }
        return set.size();
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {1, 13, 10, 12, 31};

    // Function call
    cout << "Distinct count: " << sol.countDistinctIntegers(nums) << endl;

    return 0;
}
