static const auto ban_io_sync = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        //设dp[i][j]表示以(i,j)为右下角的正方形的边长
        //因为正方形的边长相等，根据dp的定义，应该与他周围三个点的值有关
        //状态转移方程: dp[i][j] = min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]) + 1
        //建立一个变量maxlen记录当前的最大边长
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        int maxlen = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j] == '1')
                {
                    dp[i][j] = 1;
                    if(i > 0 && j > 0)
                        dp[i][j] += min( min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]);
                    maxlen = max(maxlen,dp[i][j]);
                }
            }
        }
        return maxlen * maxlen;
    }
};