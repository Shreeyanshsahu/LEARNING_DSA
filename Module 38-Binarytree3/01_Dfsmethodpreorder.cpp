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
vector<int> preorder(TreeNode *root){
    vector<int>ans;
    stack<TreeNode*> s;
    s.push(root);
    while (!s.empty())
    {           
        for (int i = 0; i < s.size(); i++)
        {
            TreeNode*temp=s.top();
            s.pop();
            if(temp->right!=NULL) s.push(temp->right);// right up and //left down due to stack it reverse access not from front
            if(temp->left!=NULL) s.push(temp->left);
            ans.push_back(temp->val);
        }
    }
    return ans;
}
vector<int> postorder(TreeNode *root){
    vector<int>ans;
    stack<TreeNode*> s;
    s.push(root);
    while (!s.empty())
    {           
        for (int i = 0; i < s.size(); i++)
        {
            TreeNode*temp=s.top();
            s.pop();
            if(temp->left!=NULL) s.push(temp->left);
            if(temp->right!=NULL) s.push(temp->right);
            ans.push_back(temp->val);
        }
    }
    return ans;
}
vector<int> inorder(TreeNode *root){
    vector<int>ans;
    stack<TreeNode*> s;
    TreeNode*node = root;
    while (!s.empty() or node)
    {           
        if(node!=NULL){
            s.push(node);
            node=node->left;
        }
        else{
            TreeNode*temp=s.top();
            s.pop();
            ans.push_back(temp->val);
            node=temp->right;
        }
    }
    return ans;
}
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    vector<int>ans=preorder(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<"  ";
    }
    cout<<endl;
    ans=postorder(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<"  ";
    }
    cout<<endl;
    ans=inorder(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<"  ";
    }
    
    return 0;
}