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
    unordered_map<int,int>map;
    TreeNode *build(vector<int>& preorder, vector<int>& inorder,int pres,int pree,int ins,int ine){
       if(pres>pree || ins>ine){
            return NULL;
       }
       TreeNode *root=new TreeNode(preorder[pres]);
       int index=map[preorder[pres]];
       int left=index-ins;

        root->left=build(preorder,inorder,pres+1,pres+left,ins,index-1);
        root->right=build(preorder,inorder,pres+left+1,pree,index+1,ine);

        return root;

    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            map[inorder[i]]=i;
        }
        
        TreeNode *root=build(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);

        return root;
    }
};