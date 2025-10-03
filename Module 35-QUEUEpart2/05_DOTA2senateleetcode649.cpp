#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include<queue>
#include <algorithm>
using namespace std;


class Solution {
public:
    string predictPartyVictory(string senate) {
        string ans1 = "Radiant";
        string ans2 = "Dire";
        queue<int> r, d;

        for (int i = 0; i < senate.length(); i++) {
            if (senate[i] == 'R') r.push(i);
            else d.push(i);
        }

        while (!r.empty() && !d.empty()) {
            if (r.front() < d.front()) {
                d.pop();
                r.push(r.front() + senate.length());
                r.pop();
            } else {
                r.pop();
                d.push(d.front() + senate.length());
                d.pop();
            }
        }

        return d.empty() ? ans1 : ans2;
    }
};

int main() {
    string senate;
    cout << "Enter senate string (R and D): ";
    cin >> senate;

    Solution sol;
    cout << "Winning Party: " << sol.predictPartyVictory(senate) << endl;

    return 0;
}
