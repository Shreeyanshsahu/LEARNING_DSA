#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(190);
    v.push_back(19);
    v.push_back(31);
    // v.at(0) = 12;
    for (int i = 0; i<=3; i++)
    {
        cout << v[i] << " ";
    }
    //sort ascending
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    //vector are passed by value so 
}