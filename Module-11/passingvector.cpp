#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void vect(vector<int> a){
    a[0] = 120;
    for (int i = 0; i<=3; i++){
        cout << a[i] <<" ";
    }
    cout<<endl;
}
void change(vector<int> & s){
    s[3] = 233;

}
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(190);
    v.push_back(19);
    v.push_back(31);
    for (int i = 0; i<=3; i++){
        cout << v[i] <<" ";
    }
    cout << endl;
    vect(v);
    for (int i = 0; i<=3; i++){
        cout << v[i] <<" ";
    }
    return 0;
    change(v);
    for (int i = 0; i<=3; i++){
        cout << v[i] <<" ";
    }
    return 0;

}