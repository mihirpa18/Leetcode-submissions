# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if not root:
            return root
        prev=None
        curr=root
        while curr and curr.val!=key:
            prev=curr
            if curr.val>key:
                curr=curr.left
            elif curr.val<key:
                curr=curr.right
        if not curr:
            return root
        flag=0
        
        if prev and prev.right==curr:
            flag=1
        
        if not curr.left and not curr.right:
            if not prev:
                return None
            curr=None
            return root

        if not prev:  
            if not curr.left:
                return curr.right
            elif not curr.right:
                return curr.left
            else:
                temp=curr.right
                l=curr.left
                while temp.left:
                    temp=temp.left
                temp.left=l
                return curr.right
        
        if flag==0:
            if not curr.left:
                prev.left=curr.right
            elif not curr.right:
                prev.left=curr.left
            else:
               
                temp=curr.right
                prev.left=temp
                l=curr.left
                while temp.left:
                    temp=temp.left
                temp.left=l
        elif flag==1:
            if not curr.left:
                prev.right=curr.right
            elif not curr.right:
                prev.right=curr.left
            else:
                temp=curr.right
                prev.right=temp
                l=curr.left
                while temp.left:
                    temp=temp.left
                temp.left=l

        return root
        
        