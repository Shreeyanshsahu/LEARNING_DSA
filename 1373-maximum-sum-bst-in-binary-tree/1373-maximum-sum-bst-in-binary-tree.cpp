class Nodes {
public:
    int largest;
    int smallest;
    int maxSize;
    int maxsum;
    bool isBst;
    Nodes(int a, int b, int c,bool bst) {
        largest = a;
        smallest = b;
        maxsum = c;
        isBst=bst;
    }
};

class Solution {
public:
    int ans=0;
    Nodes largestbst(TreeNode* root) {
        if (!root) {
            return Nodes(INT_MIN, INT_MAX, 0,true);
        }

        auto left = largestbst(root->left);
        auto right = largestbst(root->right);

        if(right.isBst)
        ans=max(ans,right.maxsum);
        if(left.isBst)
        ans=max(ans,left.maxsum);
        if (root->val > left.largest && root->val < right.smallest && left.isBst&&right.isBst) {
            ans=max(ans,left.maxsum + right.maxsum + root->val);
            return Nodes(max(root->val, right.largest),
                         min(root->val, left.smallest),
                         left.maxsum + right.maxsum + root->val,true);
        }
        
        return Nodes(INT_MAX, INT_MIN, 0,false);
    }

    int maxSumBST(TreeNode* root) {
        largestbst(root);
        return ans;
    }
};