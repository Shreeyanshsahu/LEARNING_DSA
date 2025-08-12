#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//[1,2,3,4,5,6,7,8,9,10]   weights 
// days = 5 
// minimum weight that can be transfer in day so that all weight can be minimumly transfered across 
// 5 days are 15 weight maximum limit per day  that should be output 
bool search(const vector<int>& arr,int capacity,int days){
    int count =0;
    int i = 0;
    while(days>0){
        while (i < arr.size() && count + arr[i] <= capacity){
            count += arr[i];
            i++;
        }
        days--;
        count=0;
    }
    return i==arr.size();
}



int shipWithinDays(vector<int>& weights, int days) {
        int min = *max_element(weights.begin(), weights.end()); // did it because atleat 1 weight need to be transfered 
        // in day ... else that can't be tranfered any day 
        
        int max = 0;
        // sort(weights.begin(),weights.end());
        
        while (min<max)
        {
            int mid = min + (max-min)/2;
            if(search(weights,mid,days)){
                max = mid;
            }
            else{
                min = mid+1;
            }
        }
        return min;
}



int  main(){
    vector<int>weights = {10,50,100,100,50,100,100,100};
    // cout<<"ans is"<<search(weights,159,5);
    cout<<"ans is"<<shipWithinDays(weights,5);
}