/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

/*
var inorMap map[int]int  //存放中序遍历中节点值-下标, 方便快速查找

func build(preo []int, preoStart int, preoEnd int, inor []int, inorStart int, inorEnd int) *TreeNode {
    if preoStart > preoEnd {
        return nil
    }
    root := &TreeNode{
        Val:preo[preoStart],
        Left:nil,
        Right:nil,
    }
    index, _ := inorMap[preo[preoStart]]  //找到根节点在中序遍历里的位置
    leftSize := index - inorStart
    root.Left = build(preo, preoStart + 1, preoStart + leftSize, inor, inorStart, index - 1)
    root.Right = build(preo, preoStart + leftSize + 1, preoEnd, inor, index + 1, inorEnd)
    return root
}

func buildTree(preorder []int, inorder []int) *TreeNode {
    if len(preorder) == 0{
        return nil
    }
    inorMap = make(map[int]int)
    for key, value := range(inorder) {
        inorMap [value] = key
    }
    return build(preorder, 0, len(preorder) - 1, inorder, 0, len(inorder) - 1)
}
*/
func buildTree(preorder []int, inorder []int) *TreeNode {
	if len(inorder) == 0 {
		return nil
	}

	root := new(TreeNode)
	root.Val = preorder[0]
	rootIdx := 0
	for inorder[rootIdx] != preorder[0] {
		rootIdx++
	}
	leftInorder := inorder[:rootIdx]
	rightInorder := inorder[rootIdx+1:]
	leftPreorder := preorder[1 : 1+len(leftInorder)]
	rightPreorder := preorder[1+len(leftInorder):]
	root.Left = buildTree(leftPreorder, leftInorder)
	root.Right = buildTree(rightPreorder, rightInorder)
	return root
}