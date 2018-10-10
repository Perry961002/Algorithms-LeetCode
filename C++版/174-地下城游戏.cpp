class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        //动态规划法，dp[i][j]表示位置(i,j)需要剩余最低的HP
        //由后往前依次决定在每一个位置至少要有多少血量, 这样一个位置的状态是由其下面一个和和左边一个的较小状态决定
        //因此一个基本的状态方程是: dp[i][j] = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j]
        //注意点：
        //因为要求最低的健康点数，所以左下角的HP应该剩余1
        //要求不能死，所以每一点的剩余HP应该>=1,dp[i][j] = max(min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j], 1)
        if(dungeon.empty() || dungeon[0].empty())
            return 1;
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i == m - 1 && j == n - 1)
                    dp[i][j] = max(1, 1 - dungeon[i][j]);
                else if(j == n - 1)
                    dp[i][j] = max(1,dp[i+1][j] - dungeon[i][j]);
                else if(i == m -1)
                    dp[i][j] = max(1,dp[i][j+1] - dungeon[i][j]);
                else
                    dp[i][j] = max(min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j], 1);
            }
        }
        return dp[0][0];
    }
};