class Solution {
public:
    /**
    *使用深度搜索法：
    *对未填数字的地方尝试填0到9，如果不冲突向下一个地方搜索
    *如果搜索下一个之后发现冲突，则回溯之前所填
    *当最后一行搜索完，输出结果
    */
    /*
    *dfs使用void时，满足条件后必须结束程序，不然所有的解都会被回溯
    */
    //检查当前行是否和填的num起冲突，检查当前小九宫格是否和填的num起冲突，没有返回1,否侧返回0
    int check(vector<vector<char>>& board,int x,int y,char num)
    {
        int i,j;
        for(i=0;i<9;i++)
        {
            if(board[x][i] == num) return 0;  //检查同一行
            if(board[i][y] == num) return 0; //检查同一列
        }
        int m = (x/3)*3; int n = (y/3)*3;   //确定所在九宫格
        for(i=m;i<m+3;i++)
            for(j=n;j<n+3;j++)
                if(board[i][j] == num)
                    return 0;
        return 1;
    }
    bool dfs(vector<vector<char>>& board,int x,int y)
    {
        if(x>=9)
            return true;
        if(board[x][y] == '.')
        {
            int i;
            for(i=1;i<=9;i++)
            {
                char num = (char)(i+'0');
                if(check(board,x,y,num))
                {
                    board[x][y] = num;
                    if(dfs(board,x+(y+1)/9,(y+1)%9))
			            return true;
                }
            }
            board[x][y] = '.';  //回溯
        }
        else
            return dfs(board,x+((y+1)/9),(y+1)%9);
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board,0,0);
    }
};