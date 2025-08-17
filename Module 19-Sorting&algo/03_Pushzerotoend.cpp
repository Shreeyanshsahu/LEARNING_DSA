#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> arr = {23, 24, 12, 10, 22};
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool flag = true;
        for (int x = 0; x < n - 1 - i; x++) {
            if (arr[x] > arr[x + 1]) {
                swap(arr[x], arr[x + 1]); // one-line swap
                flag = false;
            }
        }
        if (flag) break;
    }

    // Print sorted array
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
