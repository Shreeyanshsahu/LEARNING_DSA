// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// int main(){
//     vector<int> v;
//     v.push_back(1);
//     v.push_back(190);
//     v.push_back(19);
//     v.push_back(31);
//     v.push_back(1);
//     v.push_back(190);
//     v.push_back(19);
//     v.push_back(31);
//     v.push_back(1);
//     v.push_back(190);
//     v.push_back(19);
//     v.push_back(31);
//     int x = 1;
//     for (int i = v.size(); i>=0; i--){
//         if(v[i] == x){
//             cout<<i<<" ";
//             break;
//         }
//     }

// }
#include <iostream>
using namespace std;

void removeElement(int arr[], int size, int index, int newnum[], int &newSize) {
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (i != index) {
            newnum[j] = arr[i];
            j++;
        }
    }
    newSize = j; // Update the new size after removal
}

int main() {
    int nums[8] = {2, 3, 4, 5, 6, 7, 8, 9};
    int val[3] = {4, 6, 8};
    int sizeNums = sizeof(nums) / sizeof(nums[0]);
    int sizeVal = sizeof(val) / sizeof(val[0]);
    int newnums[8]; // Maximum size equal to original nums
    int newSize = sizeNums;
    
    // Loop over each value in `val` to remove from `nums`
    for (int i = 0; i < sizeVal; i++) {
        int commn = -1;
        for (int j = 0; j < newSize; j++) {
            if (val[i] == nums[j]) {
                commn = j; // Found a common element
                break;
            }
        }
        if (commn != -1) {
            removeElement(nums, newSize, commn, newnums, newSize);
            for (int k = 0; k < newSize; k++) { // Update nums with the current newnums
                nums[k] = newnums[k];
            }
        }
    }

    // Print the new array
    for (int i = 0; i < newSize; i++) {
        cout << newnums[i] << " ";
    }

    return 0;
}
