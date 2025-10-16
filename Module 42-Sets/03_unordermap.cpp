#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
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
    //inserting method one making pairs
    pair<string,int>p1;
    p1.first="Hello";
    p1.second=23;
    unordered_map<string,int>map;
    //method 2 making 
    map.insert(p1);
    map["yellow"]=21;
    map["red"]=90;
    map["world"]=22;
    map["blue"]=11;
    for(auto ele:map){
        cout<<ele.first<<" : "<<ele.second<<endl;
    }
    return 0;
}