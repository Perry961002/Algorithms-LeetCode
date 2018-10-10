/*
class Solution {
private:
    int res = 0;
public:
    //假设有n个数,那么解空间为2^n
    void dfs(int sum, int index, vector<int>& nums, int S){
        //结束条件
        if(index == nums.size()){
            if(sum == S)//找到一个解
                res ++;
            return;
        }
        //赋 '+'
        dfs(sum + nums[index], index + 1, nums, S);
        //赋 '-'
        dfs(sum - nums[index], index + 1, nums, S);
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        dfs(0, 0, nums, S);
        return res;
    }
};
*/
class Solution {
public:
    //将nums分成两部分N1,N2,对他们分配的符号分别为'+','-'
    // S = sum(N1) - sum(N2)
    // S + sum(nums) = 2 * sum(N1)
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for(auto num : nums)
            sum += num;
        //不符合要求的情况
        if(sum < S || (S+ sum) % 2 == 1 )
            return 0;
        int target = (S + sum) / 2;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        //动态规划
        for(auto num : nums)
            for(int i=target;i>=num;i--){
                dp[i] += dp[i-num];
            }
        return dp[target];
    }
};