class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        int MOD = 1000000007;
        //dp[k][i][j]表示在(i, j)位置最多移动k步可以出界的路径数
        vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(m, vector<int>(n)));
        
        for(int k=1;k<=N;k++){
            for(int x=0;x<m;x++){
                for(int y=0;y<n;y++){
                    long up = (x == 0)? 1 : dp[k-1][x-1][y];
                    long down = (x == m-1)? 1 : dp[k-1][x+1][y];
                    long left = (y == 0)? 1 : dp[k-1][x][y-1];
                    long right = (y == n-1)? 1 : dp[k-1][x][y+1];
                    dp[k][x][y] = (up + down + left + right) % MOD;
                }
            }
        }
        
        return dp[N][i][j];
    }
};