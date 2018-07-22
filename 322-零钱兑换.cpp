class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount < 0) return -1;    //非正数
        sort(coins.begin(),coins.end());
        vector<int> dp(amount + 1, amount + 1);   //dp[i]表示凑成i需要的最少个数
        dp[0] = 0;
        for(int i=1;i<=amount;++i)  //从1开始寻找
            for(int j=0;j<coins.size();++j)   //从第1中面额开始尝试
            {
                if(coins[j] <= i)  //小于需要的值
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);  //从不放和放两种情况中选最小的
                else
                    continue;
            }
        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
};