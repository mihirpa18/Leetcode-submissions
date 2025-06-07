/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *create(int k){
    struct TreeNode *temp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    temp->val = k;
    temp->left = temp->right = NULL;
    return temp;
}

struct TreeNode *build(int *pre,int *in,int n,int m,int pres,int pree,int ins,int ine){
    struct TreeNode *root;
    
    if(pres>pree || ins>ine){
        return NULL;
    }
    int t=pre[pres];
    int index;
    struct TreeNode *head=create(t);
    for(index=ins;index<ine;index++){
        if(in[index]==t)
            break;
    }
    
    int lgap=index-ins;
    head->left=build(pre,in,n,m,pres+1,pres+lgap+1,ins,index-1);
    head->right=build(pre,in,n,m,pres+lgap+1,pree,index+1,ine);
    return head;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    struct TreeNode *root=NULL;
    root=build(preorder,inorder,preorderSize,inorderSize,0,preorderSize-1,0,inorderSize-1);
    return root;
}