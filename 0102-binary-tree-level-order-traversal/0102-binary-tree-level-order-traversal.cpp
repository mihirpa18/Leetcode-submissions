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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>res;
        vector<int>temp;
        if(root==nullptr) return res;
        q.push(root);
        q.push(nullptr);
        while(q.size()>0){          
            TreeNode *node=q.front();
            q.pop();
            if(node==nullptr){
                if(!q.empty()){
                    res.push_back(temp);
                    temp.clear();
                    q.push(nullptr);
                }
                else{
                    res.push_back(temp);
                    break;
                }
            }
            else{
                temp.push_back(node->val);
                if(node->left!=nullptr){
                    q.push(node->left);
                }
                if(node->right!=nullptr){
                    q.push(node->right);
                }
            }          
        }
        return res;
    }
};