class NumMatrix {
private:
    vector<vector<int>> dp;//dp[i][j]表示从原点到(i, j)位置上所有元素的和
public:
    NumMatrix(vector<vector<int>> matrix) {
        for(int i=0;i<matrix.size();i++){
            vector<int> row;//每行上到相应位置上的累加和
            int sum = 0;
            for(int j=0;j<matrix[i].size();j++){
                sum += matrix[i][j];
                if(i == 0)
                    row.push_back(sum);
                else
                    row.push_back(sum + dp[i-1][j]);
            }
            dp.push_back(row);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        //动态规划
        int res = 0;
        if(row1 != 0 && col1 != 0)
            res = dp[row2][col2] - dp[row1 - 1][col2] - dp[row2][col1 - 1] + dp[row1 - 1][col1 - 1];
        else if(row1 == 0 && col1 != 0)
            res = dp[row2][col2] - dp[row2][col1 - 1];
        else if(row1 != 0 && col1 == 0)
            res = dp[row2][col2] - dp[row1 - 1][col2];
        else
            res = dp[row2][col2];
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */