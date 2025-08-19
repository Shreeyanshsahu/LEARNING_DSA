#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> arr = {23, 24, 12, 10, 22};
    int n = arr.size();
    for (int i = 1; i < arr.size(); i++)
    {
        int j = i;
        while(j>=1){
            if(arr[j]>arr[j-1]){
                break;
            }
            if(arr[j]<arr[j-1]){
                swap(arr[j-1],arr[j]);
            }
            j--;
        }
        
    }
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
    
}
