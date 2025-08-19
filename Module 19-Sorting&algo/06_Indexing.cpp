#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main(){
    vector<int> arr = {23, 24, 12, 10, 22};
    vector<int> ans(arr.size(),-1);
    int n = arr.size();
    for (int i = 0; i < n ; i++) {
        int min= INT16_MAX;
        int temp = 0;

        for(int j = 0;j<n;j++){
            if(ans[j]>-1){
                continue;
            }
            if(arr[j]<min){
                min = arr[j];
                temp = j;
            }
        }
        ans[temp]=i;
    }

    // Print sorted array
    for (int num : ans) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}