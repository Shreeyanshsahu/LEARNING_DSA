#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include<unordered_set>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        next = nullptr;
    }
};

int main() {
    unordered_set<int>set;
    set.insert(12);
    set.insert(1);
    set.insert(2);
    set.insert(2);
    set.insert(2);//unique value only inserted 
    // set is like a bag or a unordered map
    set.insert(92);
    set.insert(102);
    for(auto &ele:set){
        cout<<ele<<" ";
    }
    cout<<endl;
    cout<<set.size()<<endl;
    int target = 92;
    int target2=90;
    if(set.find(target)!=set.end()){
        cout<<"target found"<<endl;
    }
    else{
        cout<<"target not found"<<endl;
    }
    if(set.find(target2)!=set.end()){
        cout<<"target found"<<endl;
    }
    else{
        cout<<"target not found"<<endl;
    }
    return 0;
}