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
TreeNode* pred(TreeNode* root) {
        if(!root) return nullptr;
        root=root->left;
        while(root->right!=nullptr){
            root=root->right;
        }
        return root;
}
TreeNode* succesor(TreeNode* root) {
        if(!root) return nullptr;
        root=root->right;
        while(root->left!=nullptr){
            root=root->left;
        }
        return root;
}


int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    TreeNode* pre=pred(root);
    TreeNode* succe=succesor(root);
    cout<<" predd:"<<pre->val<<"  succesor:"<<succe->val;
    return 0;
}