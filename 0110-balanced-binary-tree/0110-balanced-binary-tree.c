/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int Height(struct TreeNode *root){
    if(root==NULL){
        return 0;
    }
    int lh=Height(root->left);
    int rh=Height(root->right);
    if(lh>rh){
        return (lh+1);
    }
    else{
        return (rh+1);
    }
}
bool isBalanced(struct TreeNode* root) {
    if(root==NULL){
        return 1;
    }
    int lh=Height(root->left);
    int rh=Height(root->right);
    if(abs(lh-rh)<=1){
        return isBalanced(root->left) && isBalanced(root->right);
    }
    else{
        return 0;
    }
}
