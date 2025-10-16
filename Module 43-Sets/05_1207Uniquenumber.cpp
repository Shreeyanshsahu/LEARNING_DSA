#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // Function to check if all element frequencies are unique
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> map;   // Stores element -> frequency
        unordered_set<int> set;        // Stores unique frequencies

        // Count frequency of each element
        for (int i = 0; i < arr.size(); i++) {
            map[arr[i]]++;
        }

        // Check if frequencies are unique
        for (auto ele : map) {
            if (set.find(ele.second) != set.end())
                return false;  // Duplicate frequency found
            set.insert(ele.second);
        }

        return true;  // All frequencies unique
    }
};

int main() {
    Solution sol;

    vector<int> arr = {1, 2, 2, 1, 1, 3};

    if (sol.uniqueOccurrences(arr))
        cout << "All occurrences are unique." << endl;
    else
        cout << "Occurrences are NOT unique." << endl;

    return 0;
}
