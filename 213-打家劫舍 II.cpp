class Solution {
public:
    int rob(vector<int>& nums) {
        //因为第一家和最后一家相联，所以第一家和最后一家不能一起被抢，所以分两次搜索
        int len = nums.size();
        if(len == 0)
            return 0;
        if(len == 1)
            return nums[0];
        
        vector<int> dp1(len);
        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);
        for(int i = 2;i < len-1;i++)
            dp1[i] = max(dp1[i-1],dp1[i-2]+nums[i]);
        vector<int> dp2(len);
        dp2[1] = nums[1];
        dp2[2] = max(nums[1], nums[2]);
        for(int i = 3;i < len;i++)
            dp2[i] = max(dp2[i-1],dp2[i-2]+nums[i]);
        return max(dp1[len-2], dp2[len-1]);
    }
};