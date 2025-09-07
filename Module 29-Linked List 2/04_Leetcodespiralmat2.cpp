#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> arr(n, vector<int>(n, 0));
        int minr = 0, minc = 0;
        int maxr = n - 1, maxc = n - 1;
        int num = 1;

        while (minr <= maxr && minc <= maxc) {
            // top row
            for (int i = minc; i <= maxc; i++) {
                arr[minr][i] = num++;
            }
            minr++;

            // right column
            for (int i = minr; i <= maxr; i++) {
                arr[i][maxc] = num++;
            }
            maxc--;

            // bottom row
            if (minr <= maxr) {
                for (int i = maxc; i >= minc; i--) {
                    arr[maxr][i] = num++;
                }
                maxr--;
            }

            // left column
            if (minc <= maxc) {
                for (int i = maxr; i >= minr; i--) {
                    arr[i][minc] = num++;
                }
                minc++;
            }
        }
        return arr;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<vector<int>> matrix = sol.generateMatrix(n);

    cout << "Spiral Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    
}
