#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> arr = {23, 24, 12, 10, 22};
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int temp = i;
        for (int x = i; x < n ; x++) {
            if (arr[temp]>arr[x]) {
                temp = x;
            }
        }
        swap(arr[i], arr[temp]); 
    }

    // Print sorted array
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;

}