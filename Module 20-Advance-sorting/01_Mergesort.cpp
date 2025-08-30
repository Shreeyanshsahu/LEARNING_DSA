#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeArray(vector<int> arr1, vector<int> arr2) {
    int i = 0, j = 0;
    vector<int> arr;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] <= arr2[j]) {
            arr.push_back(arr1[i]);
            i++;
        } else {
            arr.push_back(arr2[j]);
            j++;
        }
    }

    // Add leftovers
    while (i < arr1.size()) {
        arr.push_back(arr1[i]);
        i++;
    }
    while (j < arr2.size()) {
        arr.push_back(arr2[j]);
        j++;
    }

    return arr;
}

vector<int> mergeSort(vector<int> arr) {
    if (arr.size() <= 1) return arr;

    int mid = arr.size() / 2;

    vector<int> arr1(arr.begin(), arr.begin() + mid);
    vector<int> arr2(arr.begin() + mid, arr.end());

    arr1 = mergeSort(arr1);
    arr2 = mergeSort(arr2);

    return mergeArray(arr1, arr2);
}

int main() {
    vector<int> arr = {2, 1, 23, 9, 5, 8, 7};
    arr = mergeSort(arr);

    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
