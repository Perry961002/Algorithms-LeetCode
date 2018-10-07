class Solution {
public:
    int minSteps(int n) {
        if(n == 1)
            return 0;
        /***********************************
        vector<int> dp(n+1, INT_MAX);
        dp[0] = dp[1] = 0;
        for(int i=2;i<n+1;i++){
            for(int j=1;j<i;j++){
                //状态转移方程,条件：j能整除i
                if(i % j == 0)
                    dp[i] = min(dp[i], dp[j] + i / j);
            }
        }
        return dp[n];
        ************************************/
        //动态规划的解法分析之后发现会有很多重复
        //用递归法
        for (int i = 2; i < n; i++)
            if (n % i == 0) return i + minSteps(n / i);
        return n;
    }
};