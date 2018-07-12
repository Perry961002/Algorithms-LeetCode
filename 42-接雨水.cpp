class Solution {
public:
    int trap(vector<int>& height) {
        if( height.empty() ) return 0;
        int water = 0;  //接水量
        int leftmax = 0 , rightmax = 0;  //左右方向柱子的最大值
        int left = 0 , right = height.size() - 1;   //左右下标
        while( left < right)
        {
            leftmax = max( leftmax , height[left]);   // 更新左边的最大值
            rightmax = max( rightmax , height[right]);
            if(leftmax < rightmax)   //选择较小的向中间靠拢
            {
                water += leftmax - height[left];
                left++;
            }
            else
            {
                water += rightmax - height[right];
                right--;
            }
        }
        return water;
    }
};