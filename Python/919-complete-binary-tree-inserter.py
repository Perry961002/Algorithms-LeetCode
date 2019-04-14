# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class CBTInserter:

    def __init__(self, root: TreeNode):
        self.TreeList = [root]
        for node in self.TreeList:
            if node.left:
                self.TreeList.append(node.left)
            if node.right:
                self.TreeList.append(node.right)
        
    def insert(self, v: int) -> int:
        father, cur = self.TreeList[(len(self.TreeList) - 1) // 2], TreeNode(v)
        if father.left:
            father.right = cur
        else:
            father.left = cur
        self.TreeList.append(cur)
        return father.val

    def get_root(self) -> TreeNode:
        return self.TreeList[0]


# Your CBTInserter object will be instantiated and called as such:
# obj = CBTInserter(root)
# param_1 = obj.insert(v)
# param_2 = obj.get_root()