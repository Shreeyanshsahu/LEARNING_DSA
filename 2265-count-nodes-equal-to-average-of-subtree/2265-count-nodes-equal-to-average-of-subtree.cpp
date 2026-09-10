class Solution {
    pair<int,int> helper(TreeNode* root,int &correct){
        if(!root) return {0,0};
        auto[leftval,left]=helper(root->left,correct);
        auto[rightval,right]=helper(root->right,correct);
        if( ((root->val+leftval+rightval)/(left+right+1))==root->val)correct++;
        return {root->val+leftval+rightval,left+right+1};
        }
public:
    int averageOfSubtree(TreeNode* root) {
        int correct = 0;
        helper(root,correct);
        return correct;
    }
};