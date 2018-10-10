class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        //count记录数字出现的次数,dp[i]表示删除所有<=x的数得到的最大点数
        vector<int> count(10001, 0), dp(10001, 0);
        for(int num : nums)
            count[num]++;
        dp[1] = count[1];
        for(int i=2;i<=10000;i++){
            //如果要获得i的所有点数(i * count[i]),那么i就不能是连带删除的情况,即只能删除<=i-2的数
            //如果是连带删除的话,说明删除的都是<=i-i的数
            dp[i] = max(i * count[i] + dp[i-2], dp[i-1]);
        }
        return dp[10000];
    }
};