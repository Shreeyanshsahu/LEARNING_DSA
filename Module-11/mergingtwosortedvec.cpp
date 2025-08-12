#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> v;//first vector
    vector<int> w;//second vector
    vector<int> x;//new vector
    v.push_back(19);
    v.push_back(31);
    v.push_back(65);
    v.push_back(90);

    w.push_back(1);
    w.push_back(21);
    w.push_back(45);
    w.push_back(129);
    int j=0;
    int k=0;
    for (int i = 0; i<(v.size()+w.size()); i++)
    {
        if(v[j]<=w[k]){
            x.push_back(v[j]);
            j++;
        }
        if(v[j]>=w[k]){
            x.push_back(w[k]);
            k++;
        }
    }
    for (int i = 0; i<(v.size()+w.size()); i++)
    {
        cout<<x[i]<<" ";
    }
}