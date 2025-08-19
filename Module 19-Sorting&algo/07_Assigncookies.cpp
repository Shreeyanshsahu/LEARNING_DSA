#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());  // sort greed factors
        sort(s.begin(), s.end());  // sort cookie sizes

        int i = 0, j = 0, count = 0;
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) { // if cookie satisfies the child
                count++;
                i++;
                j++;
            } else {
                j++;  // try next bigger cookie
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> g = {1, 2, 3};   // greed factors
    vector<int> s = {1, 1};      // cookie sizes
    cout << sol.findContentChildren(g, s) << endl; // Output: 1
    return 0;
}
