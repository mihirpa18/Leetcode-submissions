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
    int eachNodeFunc(TreeNode *root,long long targetSum){
        int count=0;
        if(!root) return 0;
        if(root->val==targetSum)  count++;

        count+=eachNodeFunc(root->left,targetSum-root->val);
        count+=eachNodeFunc(root->right,targetSum-root->val);

        return count;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return 0;
        return pathSum(root->left,targetSum)+pathSum(root->right,targetSum)+eachNodeFunc(root,targetSum);

    }
};