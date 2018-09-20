class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        //先把所有的0都换成-1，这样题目变成求和为0的最长连续子数组
        
        //sum[i] = nums[1] + nums[2] +...+nums[i], sum[j] = nums[1] + nums[2] +...+nums[j], i < j
        //如果nums[i] = nums[j], 说明nums[i+1] +...+ nums[j] = 0
        
        //以<累加和，下标>建hash表
        unordered_map<int, int> hash;
        hash[0] = -1;
        int sum = 0, maxLen = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 0)
                nums[i] = -1;
            sum += nums[i];
            if(hash.find(sum) != hash.end())
                maxLen = max(maxLen, i - hash[sum]);
            else
                hash[sum] = i;
        }
        return maxLen;
    }
};