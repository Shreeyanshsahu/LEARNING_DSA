#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        bool flag = true;
        queue<int> q;

        for (int i = 0; i < students.size(); i++) {
            q.push(students[i]);
        }

        int i = 0; // students
        int j = 0; // sandwiches

        while (flag) {
            flag = false;
            i = j;
            while (i < students.size()) {
                if (q.front() == sandwiches[j]) {
                    q.pop();
                    i++;
                    j++;
                    flag = true;
                } else {
                    i++;
                    int temp = q.front();
                    q.pop();
                    q.push(temp);
                }
            }
        }
        return q.size();
    }
};

int main() {
    Solution sol;
    vector<int> students = {1,1,0,0,1};
    vector<int> sandwiches = {0,1,0,1,0};

    int result = sol.countStudents(students, sandwiches);
    cout << "Remaining students: " << result << endl;

    return 0;
}
