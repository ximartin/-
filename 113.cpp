# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def pathSum(self, root, targetSum):
        result = []

        def dfs(node, remainingSum, path):
            if not node:
                return
            
            path.append(node.val)
            remainingSum -= node.val
        
            if not node.left and not node.right and remainingSum == 0:
                result.append(path[:]) 
            
            dfs(node.left, remainingSum, path)
            dfs(node.right, remainingSum, path)
            path.pop()

        dfs(root, targetSum, [])
        return result
        