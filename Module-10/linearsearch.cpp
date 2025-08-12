// #include <iostream>
// using namespace std;

// int main() {
//     cout << "Enter your length of arr"<<endl;
//     int n; cin >> n;
//     int arr[n];
//     for(int i=0; i<=n; i++) {
//     cout << "Enter the elements of the array: ";
//         cin >> arr[i];
//     }
//     cout << "Enter the element to Search for:";
//     int search;
//     cin >> search;
//     int found = 0;
//     for(int i=0; i<n; i++){
//         if(arr[i] == search) {
//             found = 1;
//         }
//         else{
//             continue;
//         }
//     }
    
//     if(found==1){
//         cout << "Element found" << endl;
//     }
//     else{
//         cout << "Element not found" << endl;
//     }
// }

//Largest value
// #include <iostream>
// using namespace std;
// #include <climits>
// int main() {
//     cout << "Enter your length of arr"<<endl;
//     int n; cin >> n;
//     int arr[n];
//     for(int i=0; i<=n; i++) {
//     cout << "Enter the elements of the array: ";
//         cin >> arr[i];
//     }
//     int max = INT16_MIN;
//     for(int i=0; i<=n; i++) {
//     if(max<=arr[i]) {
//         max = arr[i];
//     }
//     else{
//         continue;
//     }
//     cout << max;
// }
// }

#include <iostream>
using namespace std;
#include <climits>
int main() {
    cout << "Enter your length of arr"<<endl;
    int n; cin >> n;
    int arr[n];
    for(int i=0; i<=n; i++) {
    cout << "Enter the elements of the array: ";
        cin >> arr[i];
    }
    int max = INT16_MIN;
    for(int i=0; i<=n; i++) {
    if(max<=arr[i]) {
        max = arr[i];
    }
    else{
        continue;
    }
    int secondmax = INT32_MIN;
    for(int i=0; i<=n; i++) {
    if(secondmax<=arr[i] and arr[i]!=max) {
        secondmax = arr[i];
    }
    else{
        continue;
    }
}
    cout << secondmax;
}
}