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
        #层次遍历时设置结点的next指针即可
        if root == None:
            return
        q = [root]
        while q != []:
            size = len(q)
            while size != 0:
                node, size = q.pop(0), size - 1
                if size != 0:
                    node.next = q[0]
                if node.left != None:
                    q.append(node.left)
                if node.right != None:
                    q.append(node.right)
        return root