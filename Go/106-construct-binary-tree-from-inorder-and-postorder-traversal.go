/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func buildTree(inorder []int, postorder []int) *TreeNode {
    if len(inorder) == 0 {
		return nil
	}

	root := new(TreeNode)
    root.Val = postorder[len(postorder) - 1]
	rootIdx := 0
	for inorder[rootIdx] != root.Val {
		rootIdx++
	}
    root.Left = buildTree(inorder[:rootIdx], postorder[:rootIdx])
    root.Right = buildTree(inorder[rootIdx + 1:], postorder[rootIdx :len(postorder) - 1])
	return root
}