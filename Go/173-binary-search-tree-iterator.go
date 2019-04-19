/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 type BSTIterator struct {
    s []*TreeNode
}


func Constructor(root *TreeNode) BSTIterator {
    //将最左侧的结点入栈, 这样栈顶总是某一棵树的最小结点
    iter := BSTIterator{s: []*TreeNode{}}
    for root != nil {
        iter.s = append(iter.s, root)
        root = root.Left
    }
    return iter
}


/** @return the next smallest number */
func (this *BSTIterator) Next() int {
    //取出栈顶结点
    smallest := this.s[len(this.s) - 1]
    this.s = this.s[:len(this.s) - 1]
    //将smallest的右子树的最左侧结点入栈, 即稍大的结点
    node := smallest.Right
    for node != nil {
        this.s = append(this.s, node)
        node = node.Left
    }
    return smallest.Val
}


/** @return whether we have a next smallest number */
func (this *BSTIterator) HasNext() bool {
    return len(this.s) != 0
}


/**
 * Your BSTIterator object will be instantiated and called as such:
 * obj := Constructor(root);
 * param_1 := obj.Next();
 * param_2 := obj.HasNext();
 */