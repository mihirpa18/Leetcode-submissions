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
    // vector<int>res;
    // void rsv(TreeNode *root){
    //     if(root==nullptr) return;
    //     res.push_back(root->val);
    //     rsv(root->right);
    // }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        queue<TreeNode*>q;
        if(root==nullptr) return res;
        q.push(root);
        q.push(nullptr);

        while(!q.empty()){
            TreeNode *node=q.front();
            q.pop();
            if(q.front()==nullptr){
                res.push_back(node->val);
            }
            if(node==nullptr){
                if(!q.empty()){                
                    q.push(nullptr);
                }
                else{
                    break;
                } 
            }
            else {
                if(node->left!=nullptr) q.push(node->left);
                if(node->right!=nullptr) q.push(node->right);
            }
            
        }

        return res;
    }
};