class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        maxarea = 0
        #左端下标
        left = 0
        #右端下标
        right = len(height) - 1
        while left < right:
            length = right - left
            #左端的底，要想取得更大的面积只能把left下标右移
            if height[left] < height[right]:
                maxarea = max(maxarea, height[left] * length)
                left += 1
            else:
                maxarea = max(maxarea, height[right] * length)
                right -= 1
        return maxarea