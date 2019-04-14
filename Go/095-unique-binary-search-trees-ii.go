/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */


/**
 * 结合卡特兰数和二叉搜索树的性质
 * 假设根节点为 i, 那么左子树为1 到 i - 1的二叉搜索树, 右子树为 i + 1到n的二叉搜索树
*/
func createBetween(start, end int) []*TreeNode {
    if start > end {
        return []*TreeNode{nil}
    }
    //返回只有一个结点的数组
    if start == end {
        root := new(TreeNode)
        root.Val = start
        return []*TreeNode{root}
    }
    var res []*TreeNode
    //依次选start 到end的值作为根节点，再分别递归构造左右子树, 并组合
    for i := start; i <= end; i++ {
        leftList, rightList := createBetween(start, i - 1), createBetween(i + 1, end)
        for _, left := range(leftList) {
            for _, right := range(rightList) {
                root := new(TreeNode)
                root.Val, root.Left, root.Right = i, left, right
                res = append(res, root)
            }
        }
    }
    return res
}


func generateTrees(n int) []*TreeNode {
    if n == 0 {
        return []*TreeNode{}
    }
    return createBetween(1, n)
}