#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>& v, int m, vector<int>& w, int n) {
        for(int i = 0;i<n;i++){
            v.pop_back();
        }
        int k=m-1;
        int j=n-1;
        for(int i = (m+n)-1;i>=0;i--){
            if(v[k]>w[j]){
                v[i]=v[k];
                k--;
            }
            if(v[k]<w[j]){
                v[i]=w[j];
                j--;
            }
            else{
                continue;
            }
        }
        for(int i = 0;i<v.size();i++){
            cout<<v[i]<<" ";
        }

    }

int main() {
    vector<int> v;
    vector<int> w;
    v.push_back(19);
    v.push_back(31);
    v.push_back(65);
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);

    w.push_back(1);
    w.push_back(21);
    w.push_back(45);
    w.push_back(129);
    merge(v, 3, w, 4);
    for(int i = 0;i<v.size();i++){
            cout<<v[i]<<" ";
        }

}