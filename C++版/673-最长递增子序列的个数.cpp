class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.size() < 2)
            return nums.size();
        //动态规划
        int len = nums.size(), maxLen = 1, res = 0;
        //dpLen[i]表示以nums[i]结尾的最长递增子序列的长度,dpCnt[i]表示以nums[i]结尾的最长递增子序列的个数
        vector<int> dpLen(len, 1), dpCnt(len, 1);
        for(int i=1;i<len;i++){
            for(int j=0;j<i;j++){
                //以nums[i]有更长的递增序列
                if(nums[i] > nums[j] && dpLen[i] < dpLen[j] + 1){
                    dpLen[i] = dpLen[j] + 1;
                    dpCnt[i] = dpCnt[j];
                }
                //出现了同样长度的递增序列
                else if(nums[i] > nums[j] && dpLen[i] == dpLen[j] + 1)
                    dpCnt[i] += dpCnt[j];
            }
            maxLen = max(maxLen, dpLen[i]);
        }
        //统计最长递增序列的个数
        for(int i=0;i<len;i++){
            if(dpLen[i] == maxLen)
                res += dpCnt[i];
        }
        return res;
    }
};