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
    long long sum=0;
    void helpSum(TreeNode *root,long long currNum){
        if(!root) return;
        if(!root->left && !root->right){
            sum+=currNum*10+root->val;
            return;
        } 
        currNum=currNum*10+root->val;
        helpSum(root->left,currNum);
        helpSum(root->right,currNum);
    }
public:
    int sumNumbers(TreeNode* root) {
        long long currSum=0;
        helpSum(root,currSum);

        return sum;
    }
};