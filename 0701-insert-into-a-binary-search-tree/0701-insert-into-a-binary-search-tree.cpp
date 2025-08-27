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
    // TreeNode *search(TreeNode *root,TreeNode ){
    //     if(root==nullptr){
    //         return root;
    //     }
    //     while(root){
    //         if(root->val<)
    //     }
    // }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *nn=new TreeNode(val);
        if(root==nullptr) return nn;
        TreeNode *prev;
        TreeNode *temp=root;
        while(temp){
            if(temp->val<val){
                prev=temp;
                temp=temp->right;
            }
            else if(temp->val>val){
                prev=temp;
                temp=temp->left;
            }
        }
        if(val<prev->val) prev->left=nn;
        else prev->right=nn;

        return root;
    }
};