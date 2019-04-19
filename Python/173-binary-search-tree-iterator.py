# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class BSTIterator:
    """
    BST的最小结点就是最左侧的结点
    BST的中序遍历结果是一个递增的序列, 借助栈来完成
    """
    def __init__(self, root: TreeNode):
        self.s = []
        #将最左侧的结点入栈, 这样栈顶总是某一棵树的最小结点
        while root != None:
            self.s.append(root)
            root = root.left

    def next(self) -> int:
        """
        @return the next smallest number
        """
        smallest = self.s.pop()
        #将smallest的右子树的最左侧结点入栈, 即稍大的结点
        node = smallest.right
        while node != None:
            self.s.append(node)
            node = node.left
        return smallest.val

    def hasNext(self) -> bool:
        """
        @return whether we have a next smallest number
        """
        return self.s != []


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()