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
    bool identical(TreeNode *root,TreeNode *st){
        if(root==nullptr && st==nullptr){
            return true;
        }
        if(root==nullptr || st==nullptr){
            return false;
        }
        return (root->val==st->val) && identical(root->left,st->left) && identical(root->right,st->right);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr){
            return false;
        }
        if(identical(root,subRoot)){
            return true;
        }
       
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);

    }
};