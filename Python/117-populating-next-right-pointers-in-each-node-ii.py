"""
# Definition for a Node.
class Node:
    def __init__(self, val, left, right, next):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        head = root
        """
        root为树结点的迭代器
        row是前一层的第一个结点
        开始遍历每层第一个结点时, 把row的next指针指向下一层的第一个结点
        遍历到每次最后一个结点时, 把root置为row.next, 把row.next置为空
        """
        row = Node(0, None, None, None)
        it = row #一个设置next指针的迭代器
        while root != None:
            if root.left != None:
                it.next = root.left
                it = it.next
            if root.right != None:
                it.next = root.right
                it = it.next
            root = root.next
            if root == None:
                root, it, row.next = row.next, row, None
        return head