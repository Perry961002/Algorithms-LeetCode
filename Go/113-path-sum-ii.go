/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 var result [][]int

 //dfs方式得到所有路径
 func getPath(root *TreeNode, sum int, res []int) (){
	 res = append(res, root.Val)
	 //只有根结点且满足和
	 if root.Left == nil && root.Right == nil && root.Val == sum {
		 resCopy := make([]int, len(res))
		 copy(resCopy, res)
		 result = append(result, resCopy)
		 return
	 }
	 //递归并回溯
	 sum -= root.Val
	 if root.Left != nil {
		 getPath(root.Left, sum, res)
	 }
	 if root.Right != nil {
		 getPath(root.Right, sum, res)
	 }
 }
 
 func pathSum(root *TreeNode, sum int) [][]int {
	 result = [][]int{}
	 res := []int{}
	 if root == nil {
		 return result
	 }
	 getPath(root, sum, res)
	 return result
 }