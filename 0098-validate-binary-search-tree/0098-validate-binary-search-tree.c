/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isValidBSTHelper(struct TreeNode* root, struct TreeNode** prev) {
    if (root != NULL) {
        if (!isValidBSTHelper(root->left, prev)) {
            return false;
        }
        if (*prev != NULL && root->val <= (*prev)->val) {
            return false;
        }
        *prev = root;
        return isValidBSTHelper(root->right, prev);
    }
    return true;
}

bool isValidBST(struct TreeNode* root) {
    struct TreeNode* prev = NULL;
    return isValidBSTHelper(root, &prev);
}