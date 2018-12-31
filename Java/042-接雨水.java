class Solution {
    public int trap(int[] height) {
        if (height.length == 0)
            return 0;
        int water = 0; // 接水量
        int leftmax = 0, rightmax = 0; // 左右方向柱子的最大值
        int left = 0, right = height.length - 1; // 左右下标
        while (left < right) {
            leftmax = Math.max(leftmax, height[left]); // 更新左边的最大值
            rightmax = Math.max(rightmax, height[right]);
            if (leftmax < rightmax) // 选择较小的向中间靠拢
            {
                water += leftmax - height[left];
                left++;
            } else {
                water += rightmax - height[right];
                right--;
            }
        }
        return water;
    }
}