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
    int c=0;
    void count(TreeNode *root,int maxele){
        if(root==NULL) return;
        if(root->val>=maxele){
            c++;
            maxele=root->val;
        }
        count(root->left,maxele);
        count(root->right,maxele);
    }
public:
   
    int goodNodes(TreeNode* root) {
        
        count(root,root->val);
        return c;
    }
};