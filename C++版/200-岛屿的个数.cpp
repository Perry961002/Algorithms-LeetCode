static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    void dfs(vector<vector<char>> &grid, int i, int j, int m, int n)
    {
        grid[i][j] = '0';
        if(i > 0 && grid[i-1][j] == '1')
            dfs(grid, i-1, j, m, n);
        if(i < m-1 && grid[i+1][j] == '1')
            dfs(grid, i+1, j, m, n);
        if(j > 0 && grid[i][j-1] == '1')
            dfs(grid, i, j-1, m, n);
        if(j < n-1 && grid[i][j+1] == '1')
            dfs(grid, i, j+1, m, n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        if(grid.empty() || grid[0].empty())
            return result;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i ++)
        {
            for(int j = 0; j < n; j ++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(grid, i, j, m, n);
                    result ++;
                }
            }
        }
        return result;
    }
};