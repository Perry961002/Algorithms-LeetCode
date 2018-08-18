class Solution {
public:
    //增加两个状态，2表示由活状态变为死状态，3表示由死状态变成活状态
    //统计周围活细胞的个数
    int livenum(vector<vector<int>>& board, int& x, int& y)
    {
        int num = 0;
        for(int i=x-1;i<=x+1;i++)
        {
            for(int j=y-1;j<=y+1;j++)
            {
                if(i==x && j==y)
                    continue;
                if(i>=0 && i< board.size() && j>=0 && j<board[0].size() && (board[i][j]==1 || board[i][j]==2))
                    num ++;
            }
        }
        return num;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size(), col = board[0].size();
        if(row==0 || col==0)
            return;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                int num = livenum(board, i, j);
                if(num == 2)//如果活细胞周围八个位置有两个，则该位置活细胞仍然存活
                    continue;
                if(num == 3)//如果死细胞周围正好有三个活细胞，则该位置死细胞复活; 如果活细胞周围八个位置有三个活细胞，则该位置活细胞仍然存活
                    board[i][j] = (board[i][j] == 0)? 3 : 1;
                else//如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
                    board[i][j] = (board[i][j] == 1)? 2 : 0;
            }
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                board[i][j] %= 2;
            }
        }
    }
};