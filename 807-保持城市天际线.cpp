class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int len = grid.size() , result = 0;
        vector<int> row(len);  //行的最大值
        vector<int> col(len);  //列的最大值
        for(int i=0;i<len;i++)
        {
            int max = grid[i][0];
            for(int j=1;j<len;j++)
                if( max < grid[i][j] )
                    max = grid[i][j];
            row[i] = max;
        }
        for(int i=0;i<len;i++)
        {
            int max = grid[0][i];
            for(int j=1;j<len;j++)
                if( max < grid[j][i] )
                    max = grid[j][i];
            col[i] = max;
        }
        for(int i=0;i<len;i++)
            for(int j=0;j<len;j++)
                result += min( row[i] , col[j] ) - grid[i][j];
        return result;
    }
};