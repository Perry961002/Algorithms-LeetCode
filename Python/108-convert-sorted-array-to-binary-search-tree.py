# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        def BSTBuild(start: int, end: int) -> TreeNode:
            if start > end:
                return None
            mid = (start + end) // 2
            root = TreeNode(nums[mid])
            #递归构造
            root.left = BSTBuild(start, mid - 1)
            root.right = BSTBuild(mid + 1, end)
            return root
        if nums == []:
            return None
        return BSTBuild(0, len(nums) - 1)