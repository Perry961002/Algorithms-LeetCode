class Solution {
public:
    /*
    *记忆化搜索
    */
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1) return 0;
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 0; i < m; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                if (obstacleGrid[i][j] == 1) 
                    dp[j] = 0;
                else if (j > 0) 
                    dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];

    }
};