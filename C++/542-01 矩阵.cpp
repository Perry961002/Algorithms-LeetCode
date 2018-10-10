class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        //广度优先搜索
        int m = matrix.size();int n = matrix[0].size();
        //移动方向
        vector<vector<int>> move = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int> > que;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0)
                    que.push({i, j});
                else
                    matrix[i][j] = INT_MAX;
            }
        }
        while(!que.empty()){
            auto now = que.front();
            que.pop();
            for(auto mo : move){
                //下个点的坐标
                int x = now.first + mo[0];int y = now.second + mo[1];
                if( x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[now.first][now.second] )
                    continue;
                matrix[x][y] = matrix[now.first][now.second] + 1;
                que.push({x, y});
            }
        }
        return matrix;
    }
};