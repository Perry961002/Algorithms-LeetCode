# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        if root == None:
            return ' #'
        res, que = '', [root]
        #层次遍历
        while que != []:
            node = que.pop(0)
            if node:
                res += ' ' + str(node.val)
                que.append(node.left)
                que.append(node.right)
            else:
                res += ' #'
        return res

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        #空树
        if data == ' #':
            return None
        #将data按' '进行切片
        strList = data.split()
        root = TreeNode(int(strList.pop(0))) #根节点
        que, val = [root], ''
        #层次遍历
        while que != []:
            cur = que.pop(0)
            val = strList.pop(0)
            if val != '#':
                node = TreeNode(int(val))
                que.append(node)
                cur.left = node
            val = strList.pop(0)
            if val != '#':
                node = TreeNode(int(val))
                que.append(node)
                cur.right = node
        return root

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))