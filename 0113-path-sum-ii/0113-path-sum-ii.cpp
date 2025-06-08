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
    vector<int>temp;
    vector<vector<int>>res;
    TreeNode *node;
    void helper(TreeNode *root,int targetSum,int sum){
        if(!root) return;
        sum+=root->val;
        temp.push_back(root->val);
        if(!root->left && !root->right && sum!=targetSum){
            temp.pop_back();
            sum-=root->val;
            return;
        } 
        
        if(!root->left && !root->right && sum==targetSum){
            res.push_back(temp);
            temp.clear();
            temp.push_back(node->val);
            sum=0;
            return;
        }
        helper(root->left,targetSum,sum);
        helper(root->right,targetSum,sum);
        
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum=0;
        node=root;
        helper(root,targetSum,sum);

        return res;
    }
};