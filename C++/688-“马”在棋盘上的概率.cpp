class Solution {
private:
    //8个移动方向
    vector<pair<int, int>> move = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
public:
    double knightProbability(int N, int K, int r, int c) {
        if(K == 0)//特殊输入的判断
            return 1.0;
        if(r < 0 || c < 0 || c >= N || r >= N)//特殊输入的判断
            return 0.0;
        //动态规划,dp[k][i][j]表示在(i, j)位置移动k步落在棋盘上的概率
        vector<vector<vector<double>>> dp(K+1, vector<vector<double>>(N, vector<double>(N, 0.0)));
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                dp[0][i][j] = 1.0;
            }
        }
        for(int k=1;k<=K;k++){
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    double pro = 0.0;//概率
                    for(auto m : move){
                        //新的坐标点
                        int x = i + m.first;
                        int y = j + m.second;
                        //出棋盘
                        if(x < 0 || y <0 || x >= N || y >= N)
                            continue;
                        else
                            pro += dp[k-1][x][y] / 8.0;
                    }
                    dp[k][i][j] = pro;
                }
            }
        }
        return dp[K][r][c];
    }
};