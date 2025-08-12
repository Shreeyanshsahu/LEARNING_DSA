#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool hourverify(const vector<int>& time, long long totaltrips, long long hour) {
        long long trips = 0;
        for (int t : time) {
            trips += hour / t;
            if (trips >= totaltrips) return true; // early exit
        }
        return trips >= totaltrips;
    }

    long long minimumTime(const vector<int>& time, long long totalTrips) {
        long long minTime = *min_element(time.begin(), time.end());
        long long lo = 1;
        long long hi = minTime * totalTrips;

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (hourverify(time, totalTrips, mid))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};

int main() {
    vector<int> time = {1, 2, 3};
    long long totalTrips = 5;

    Solution sol;
    cout << sol.minimumTime(time, totalTrips) << endl; // Output: 3
}
