/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 var maxSum int
 func max(x, y int) int {
	 if x > y {
		 return x
	 }
	 return y
 }
 //这个函数返回的是从root开始的走某个子树的最长路径值(局部), 在这个函数里面处理全局最大值
 func getMaxSum(root *TreeNode) int {
	 /**
	  * 在每一个节点时有下面4种情况：
	  *  1.root->val(左、右子树最大值都是非正的)
	  *  2.leftmax + root->val(右子树最大值非正，左子树最大值是正值)
	  *  3.rightmax + root->val(左子树最大值非正，右子树最大值是正值)
	  *  4.rightmax + leftmax + root->val(左子树最大值是正值，右子树最大值是正值)
	  * 从上面情况中选出成立的，与暂存的最大值比较
	  */
	 if root == nil {
		 return 0
	 }
	 //递归, 从左右子树开始的最大值
	 leftMax, rightMax := getMaxSum(root.Left), getMaxSum(root.Right)
	 rootMax := root.Val + max(leftMax, 0) + max(rightMax, 0) //考虑合并两个子树方向上的最大值
	 maxSum = max(maxSum, rootMax)
	 //返回从root开始的走某个子树的最长路径值
	 return root.Val + max(max(leftMax, rightMax), 0)
 }
 
 func maxPathSum(root *TreeNode) int {
	 maxSum = root.Val
	 getMaxSum(root)
	 return maxSum
 }