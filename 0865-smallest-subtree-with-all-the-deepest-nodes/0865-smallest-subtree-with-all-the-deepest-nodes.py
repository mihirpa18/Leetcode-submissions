# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def subtreeWithAllDeepest(self, root: Optional[TreeNode]) -> Optional[TreeNode]:

        def maxLvl(root):
            if root is None:
                return 0
            if root.left is None and root.right is None:
                return 1
            maxi=max(maxLvl(root.left),maxLvl(root.right))
            return maxi+1
        maxi=maxLvl(root)
        # print(f"maxi-{maxi}")
        
        # q=deque()
        # q.append(root)
        # lvl=0
        # while q:
        #     size=len(q)
        #     for i in range(size):
        #         node=q.pop()
        #         print(node.val)
        #         print(f"m-{maxLvl(node)}")
        #         print(f"l-{lvl}")
        #         if maxLvl(node)+lvl==maxi:
        #             if not node.left and not node.right:
        #                 return node
        #             if maxLvl(node.left)==maxLvl(node.right):
        #                 return node
        #         if node.left:
        #             q.append(node.left)
        #         if node.right:
        #             q.append(node.right)
        #     lvl+=1
        def solve(node):
            if not node:
                return None
            if not node.left and not node.right:
                return node
            if not node.left:
                node=solve(node.right)
                return node
            if not node.right:
                node=solve(node.left)
                return node

            left=maxLvl(node.left)
            right=maxLvl(node.right)
            if maxLvl(node.left)==maxLvl(node.right):
                return node
            
            if(left>right):
                node=solve(node.left)
            else:
                node=solve(node.right)
            return node

        return solve(root)


        # print(maxi)
