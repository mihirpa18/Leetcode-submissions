/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    pair<int,int> help(TreeNode *root){
        if(!root) return {0,0};

        pair<int,int> left=help(root->left);
        pair<int,int> right=help(root->right);

        int take=root->val+left.second+right.second;
        int notTake=max(left.first,left.second)+max(right.first,right.second);

        return {take,notTake};
    }
public:
    int rob(TreeNode* root) {
        if(!root) return 0;
        pair<int,int> res=help(root);
        return max(res.first,res.second);
    }
};