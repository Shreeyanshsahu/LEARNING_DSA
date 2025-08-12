#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void swap(vector<int>& v){
    int i = 0;
    int j = v.size()-1;
    while(i<j){
        if(v[i]<0){
            i++;
        }
        if(v[j]>=0){
            j--;
        }
        if(v[i]>=0 and v[j]<0){
            int temp=v[i];
            v[i]=v[j];
            v[j]=temp;
        }
    }
}
int main(){
    vector<int> v;
    v.push_back(90);
    v.push_back(-89);
    v.push_back(65);
    v.push_back(19);
    v.push_back(31);
    v.push_back(-30);
    v.push_back(780);
    v.push_back(-981);
    v.push_back(-78);
    v.push_back(-34);
    v.push_back(787);
    v.push_back(12);
    v.push_back(-1);
    v.push_back(-78);
    v.push_back(0);
    v.push_back(1);
    // v.at(0) = 12;
    for (int i = 0; i<v.size(); i++)
    {
        cout << v[i] << " ";
    }
    swap(v);
    cout<<endl;
    for (int i = 0; i<v.size(); i++)
    {
        cout << v[i] << " ";
    }
}