class Solution {
public:
    int numSquares(int n) {
        //dp[i]表示i可以拆成的完全平方数的最小个数
        vector<int> dp(n+1, n+1);
        //i正好就是完全平方数
        for(int i=0;i*i<=n;i++)
        {
            dp[i*i] = 1;
        }
        for(int i=0;i<=n;i++)
            for(int j=0;i+j*j<=n;j++)
            {
                dp[i+j*j] = min(dp[i] + 1, dp[i+j*j]);
            }
        return dp[n];
    }
};