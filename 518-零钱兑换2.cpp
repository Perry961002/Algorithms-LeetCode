class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //很简单的动态规划
        vector<int> dp(amount+1, 0);//表示i元的搭配个数
        dp[0] = 1;
        for(auto coin : coins)
        {
            for(int i =coin;i<=amount;i++)
                dp[i] += dp[i-coin];
        }
        return dp[amount];
    }
};