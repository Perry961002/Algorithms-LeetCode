/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 type CBTInserter struct {
    list [] *TreeNode
}


func Constructor(root *TreeNode) CBTInserter {
    var TreeList CBTInserter
    var queue []*TreeNode
    queue = append(queue, root)
    for len(queue) != 0 {
        cur := queue[0]
        queue = queue[1:]
        if cur.Left != nil {
            queue = append(queue, cur.Left)
        }
        if cur.Right != nil {
            queue = append(queue, cur.Right)
        }
        TreeList.list = append(TreeList.list, cur)
    }
    return TreeList
}


func (this *CBTInserter) Insert(v int) int {
    var cur TreeNode
    cur.Val = v
    father := this.list[(len(this.list) - 1) / 2]
    if father.Left == nil {
        father.Left = &cur
    } else {
        father.Right = &cur
    }
    this.list = append(this.list, &cur)
    return father.Val
}


func (this *CBTInserter) Get_root() *TreeNode {
    return this.list[0]
}


/**
 * Your CBTInserter object will be instantiated and called as such:
 * obj := Constructor(root);
 * param_1 := obj.Insert(v);
 * param_2 := obj.Get_root();
 */