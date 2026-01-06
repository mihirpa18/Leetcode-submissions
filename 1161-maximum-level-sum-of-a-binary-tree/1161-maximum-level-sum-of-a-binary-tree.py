# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        q=deque()
        if root==None:
            return 0
        
        q.append(root)
        res=float('-inf')
        level=0
        lvl=0

        while q:
            sum=0
            size=len(q)
            lvl+=1
            for i in range(size):
                node=q.popleft()
                sum+=node.val
                if node.left:
                    q.append(node.left)
                if(node.right):
                    q.append(node.right)  

            if sum>res:
                res=sum
                level=lvl


        return level;         
