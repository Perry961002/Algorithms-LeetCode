class Solution {
public:
    int getMaxLen(vector<vector<int>>& matrix, vector<vector<int>>& maxLen, int m, int n)
    {
        int maxlen = 1;
        //记忆化，被搜过了就返回他位置上的最长递增子序列的长度
        if(maxLen[m][n] != 0)
            return maxLen[m][n];
        if(m > 0 && matrix[m-1][n] > matrix[m][n]) //向上
            maxlen = max(maxlen, getMaxLen(matrix, maxLen, m-1, n) + 1);
        if(m < matrix.size() - 1 && matrix[m+1][n] > matrix[m][n]) //向下
            maxlen = max(maxlen, getMaxLen(matrix, maxLen, m+1, n) + 1);
        if(n > 0 && matrix[m][n-1] > matrix[m][n]) //向左
            maxlen = max(maxlen, getMaxLen(matrix, maxLen, m, n-1) + 1);
        if(n < matrix[0].size()-1 && matrix[m][n+1] > matrix[m][n]) //向右
            maxlen = max(maxlen, getMaxLen(matrix, maxLen, m, n+1) + 1);
        maxLen[m][n] = maxlen;
        return maxlen;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        int result = 0, m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> maxLen(m, vector<int>(n, 0));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                result = max(result, getMaxLen(matrix, maxLen, i, j));
        return result;
    }
};