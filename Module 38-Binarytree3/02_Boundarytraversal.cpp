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
void leftboundary(TreeNode* root,vector<int>&ans){
    if(!root or !root->left) return;
    else{
        ans.push_back(root->val);
        leftboundary(root->left,ans);
    }
}
void rightboundaryreverse(TreeNode* root,vector<int>&ans){
    if(!root or !root->right) return;
    else{
        leftboundary(root->right,ans);
        ans.push_back(root->val);
    }
    
}
void leafNode(TreeNode* root,vector<int>&ans){
    if(!root) return;
    if(!root->left and !root->right) ans.push_back(root->val);
    else{
        leafNode(root->left,ans);
        leafNode(root->right,ans);
    }
}
vector<int> showboundary(TreeNode* root){
    vector<int>ans;
    leftboundary(root,ans);
    leafNode(root,ans);
    rightboundaryreverse(root->right,ans);
    return ans;
}

int main() {
    /*
                      50
                   /       \
                25           75
              /   \         /   \
            12     40      60     90
           /         \       \    /  \
          6           45      70 92   95
         / \          /          /      \
        3   9       42         91       100
             \         \
              10        43
                        /
                      41
*/
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(25);
    root->right = new TreeNode(75);

    root->left->left = new TreeNode(12);
    root->left->right = new TreeNode(40);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(90);

    root->left->left->left = new TreeNode(6);
    root->left->left->left->left = new TreeNode(3);
    root->left->left->left->right = new TreeNode(9);
    root->left->left->left->right->right = new TreeNode(10);

    root->left->right->right = new TreeNode(45);
    root->left->right->right->left = new TreeNode(42);
    root->left->right->right->left->right = new TreeNode(43);
    root->left->right->right->left->right->left = new TreeNode(41);

    root->right->left->right = new TreeNode(70);
    root->right->right->right = new TreeNode(95);
    root->right->right->right->right = new TreeNode(100);
    root->right->right->left = new TreeNode(92);
    root->right->right->left->left = new TreeNode(91);
    vector<int>ans=showboundary(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<"  ";
    }
    
    return 0;
}