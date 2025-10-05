#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        next = nullptr;
    }
};
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};
void displayTree(TreeNode *head){
    if(!head) return;
    cout<<head->val<<" ";
    displayTree(head->left);
    displayTree(head->right);
}
int sum(TreeNode *head){
    if(!head) return 0;
    // cout<<head->val<<" ";
    int count = head->val;
    count +=sum(head->left);
    count +=sum(head->right);
    return count;
}
int size(TreeNode *head){
    if(!head) return 0;
    // cout<<head->val<<" ";
    int count = 1;
    count +=size(head->left);
    count +=size(head->right);
    return count;
}
int maximum(TreeNode *head){
    if(!head) return INT16_MIN;
    // cout<<head->val<<" ";
    int maxi = head->val;
    maxi =max(maxi,max(maximum(head->left),maximum(head->right)));
    return maxi;
}
int level(TreeNode *head){
    if(!head) return 0;
    // cout<<head->val<<" ";
    int levels = 1;
    levels =max(level(head->left),level(head->right))+1;
    return levels;
}

int main() {
    TreeNode * a= new TreeNode(10);
    TreeNode * b= new TreeNode(20);
    TreeNode * c= new TreeNode(30);
    TreeNode * d= new TreeNode(40);
    TreeNode * e= new TreeNode(50);
    TreeNode * f= new TreeNode(60);
    TreeNode * g= new TreeNode(70);
    // TreeNode * h= new TreeNode(80);
    //                  a 
    //          b               c 
    //      d      e        f       g
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    displayTree(a);
    cout<<endl;
    cout<<sum(a);
    cout<<endl;
    cout<<size(a);
    cout<<endl;
    cout<<maximum(a);
    cout<<endl;
    cout<<level(a);
    return 0;
}