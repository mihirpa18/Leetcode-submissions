# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:

        self.totalSum=0
        mod=10**9+7
        def dfsTotal(node):
            if not node:
                return 0
            self.totalSum=node.val+dfsTotal(node.left)+dfsTotal(node.right)

            return self.totalSum

        self.res=0
        def dfsSubtree(node):
            if not node:
                return 0
            
            subSum=node.val+dfsSubtree(node.left)+dfsSubtree(node.right)

            self.res=max(self.res,(self.totalSum-subSum)*subSum)

            return subSum
            
        dfsTotal(root)
        dfsSubtree(root)

        return self.res%mod