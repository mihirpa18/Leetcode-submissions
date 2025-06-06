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
    int dummy;
    long smin=LONG_MAX;
    void helper(TreeNode *root){
        if(root==nullptr) return;
        if(root->val>dummy && root->val<smin){
            smin=root->val;
        }
        else if(root->val==dummy){
            helper(root->left);
            helper(root->right);
        }
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        dummy=root->val;
        helper(root);

        return smin==LONG_MAX?-1:smin;
    }
};