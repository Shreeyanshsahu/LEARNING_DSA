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
TreeNode* construct(vector<int>arr) {
        if (arr.empty()) return nullptr;

    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(arr[0]);
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        TreeNode* temp = q.front();
        q.pop();

        // Left child
        if (i < arr.size() && arr[i] != INT_MIN) {
            temp->left = new TreeNode(arr[i]);
            q.push(temp->left);
        }
        i++;

        // Right child
        if (i < arr.size() && arr[i] != INT_MIN) {
            temp->right = new TreeNode(arr[i]);
            q.push(temp->right);
        }
        i++;
    }
    return root;
}
vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();// multi surce bfs s we have seen
            vector<int>v;
            for(int i=0;i<s;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left!=NULL)q.push(temp->left);
                if(temp->right!=NULL)q.push(temp->right);
                v.push_back(temp->val);
            }
            ans.push_back(v);
        }
        return ans;
    }
int main() {
    vector<int>arr={1,2,3,INT_MIN,16,30};
    TreeNode *root = construct(arr);
    vector<vector<int>> ans = levelOrder(root);//alternate good method
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<"  ";
        }
        cout<<endl;
    }
    
    return 0;
    return 0;
}