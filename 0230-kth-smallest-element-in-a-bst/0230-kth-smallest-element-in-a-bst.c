/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 void Kthsmallest(struct TreeNode* root, int k,int *index,int *res){
    if(root==NULL){
        return;
    }
    int c=0;
    Kthsmallest(root->left,k,index,res);
    (*index)++;

    if(*index == k){
         *res=root->val;
         return;
    }
    Kthsmallest(root->right,k,index,res);
 }
int kthSmallest(struct TreeNode* root, int k) {
    int index=0;
    int res=0;
    Kthsmallest(root,k,&index,&res);
    return res;
}