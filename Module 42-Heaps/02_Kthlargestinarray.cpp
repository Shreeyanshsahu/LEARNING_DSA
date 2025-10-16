#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Min-heap that stores the k largest elements
        priority_queue<int, vector<int>, greater<int>> heap;

        for (int num : nums) {
            heap.push(num);
            if (heap.size() > k) {
                heap.pop(); // remove smallest element if heap exceeds size k
            }
        }
        return heap.top(); // top is kth largest element
    }
    int findsmallestt(vector<int>& nums, int k) {
        // Min-heap that stores the k largest elements
        priority_queue<int> heap;

        for (int num : nums) {
            heap.push(num);
            if (heap.size() > k) {
                heap.pop(); // remove smallest element if heap exceeds size k
            }
        }
        return heap.top(); // top is kth largest element
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    cout << "The " << k << "th largest element is: "
         << sol.findKthLargest(nums, k) << endl;
    cout << "The " << k << "th smallest element is: "
         << sol.findsmallestt(nums, k) << endl;

    return 0;
}