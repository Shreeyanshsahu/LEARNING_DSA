#include <iostream>
using namespace std;

int countcheck(int piles[], int n, int mid) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += (piles[i] + mid - 1) / mid; // ceil division
    }
    return total;
}

int minEatingSpeed(int piles[], int n, int h) {
    // Find max pile manually
    int high = piles[0];
    for (int i = 1; i < n; i++) {
        if (piles[i] > high) {
            high = piles[i];
        }
    }

    int low = 1, ans = high;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        int count = countcheck(piles, n, mid);
        
        if (count <= h) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int piles[] = {3, 6, 7, 11};
    int n = 4;
    int h = 8;
    cout << minEatingSpeed(piles, n, h) << endl; // Output: 4
    return 0;
}
