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
int findlevel(TreeNode *root){
    if(!root) return 0;
    int level=1;
    level = 1+max(findlevel(root->left),findlevel(root->right));
    return level;
}
void nthlevelele(TreeNode *root,int current,int level){
    if(!root) return;
    if(current==level){
        cout<<root->val<<"  ";
        return;
    }
    current++;
    nthlevelele(root->left, current,level);
    nthlevelele(root->right, current,level);
    return;
}

void alllevel(TreeNode *root){
    for (int i = 1; i <= findlevel(root); i++)
    {
        nthlevelele(root,1,i);
        cout<<endl;
    }
    return;
    
}
int main() {
    // Create a sample tree:
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    // cout<<findlevel(root);
    alllevel(root);
    
    return 0;
}