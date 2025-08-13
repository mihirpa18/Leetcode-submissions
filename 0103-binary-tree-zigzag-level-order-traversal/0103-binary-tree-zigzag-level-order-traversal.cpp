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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        vector<vector<int>>res;
        if(root==nullptr) return res;
        while(!q.empty()){
            int n=q.size();
            vector<int>temp;
            for(int i=0;i<n;i++){
                TreeNode *top=q.front();
                q.pop();
                if(top) temp.push_back(top->val);
                if(top->left!=nullptr) q.push(top->left);
                if(top->right!=nullptr) q.push(top->right);
            }
            if(level%2!=0) reverse(temp.begin(),temp.end());
            level++;
            res.push_back(temp); 
        }

        return res;

    }
};