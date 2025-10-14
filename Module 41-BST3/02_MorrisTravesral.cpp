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
void Morristraverse(TreeNode* root){
    TreeNode*curr= root;
    TreeNode*pred;
    while (curr!=NULL)
    {
        if(curr->left!=NULL){ // step 1 check if current left exist
            pred=curr->left;
            while (pred->right!=NULL && pred->right!=curr)// step get predesor
            {
                pred=pred->right;
            }
            // when loop break it will be on of the 2 reason pred->right null or pred is current
            // if pred right Null link with current
            // if pred right is null unlink it and visit it like cout<<it 
            if(pred->right==NULL){
                pred->right=curr;
                curr=curr->left;
            }
            if(pred->right==curr){
                //unlink
                pred->right=NULL;
                cout<<curr->val;
                curr=curr->right;// move right 
            }
            
        }
        else{//current left not exist
            cout<<curr->val;
            curr=curr->right;// move right 
        }
    }
    //algo work like link link link and then unlink show unlink show move right if left not available
}
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(0);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(1);
    Morristraverse(root);
    return 0;
}
//O(1) space complexity