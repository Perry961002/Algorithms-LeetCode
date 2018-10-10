class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //sum[i] = nums[1] + nums[2] +...+nums[i], sum[j] = nums[1] + nums[2] +...+nums[j], i < j
        //如果nums[i] = nums[j] - k, 说明nums[i+1] +...+ nums[j] = k
        
        //以<累加和，下标>建hash表
        unordered_map<int, int> hash;
        hash[0] = 1;//和525题不同，因为是求数组的个数，所以0的时候设为1
        int sum = 0, result = 0;
        for(auto n : nums)
        {
            sum += n;
            result += hash[sum - k];
            hash[sum] ++;
        }
        return result;
    }
};