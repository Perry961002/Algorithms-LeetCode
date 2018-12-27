class Solution {
    public int maxArea(int[] height) {
        int maxarea = 0; // 最大面积
        int left = 0; // 左下标
        int right = height.length - 1; // 右下标
        while (left < right) // 从两个方向开始寻找
        {
            maxarea = Math.max(maxarea, Math.min(height[left], height[right]) * (right - left)); // 面积由高度小的决定，并更新maxarea
            if (height[left] < height[right]) // 左边的低，向右搜索
                left++;
            else
                right--;
        }
        return maxarea;
    }
}