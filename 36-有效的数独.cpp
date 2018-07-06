class Solution {
public:
    bool isValidBlock(vector<vector<char>>& board,int x,int y){
        set<int> test;
        for(int i = x;i<x+3;++i){
            for(int j = y;j < y+3;++j)
            {
                if(board[i][j] == '.')
                {
                    continue;
                }
                if(board[i][j] <= '9' && board[i][j] >= '1')
                {
                    if(test.find(board[i][j]-'0')==test.end())  //判断是否存在
                    {
                        test.insert(board[i][j]-'0');
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
    
    bool isValidRow(vector<vector<char>>& board,int row){
        set<int> test;
        for(int i = 0;i < 9;++i)
        {
           if(board[row][i] == '.')
           {
               continue;
           }
           if(test.find(board[row][i]-'0')==test.end())
           {
               test.insert(board[row][i]-'0');
           }
            else
            {
               return false;
            }
        }
        
        return true;
    }
    
    bool isValidColum(vector<vector<char>>& board,int colum)
    {
        set<char> test;
        for(int i = 0;i<9;++i)
        {
           if(board[i][colum] == '.')
           {
               continue;
           }
           if(test.find(board[i][colum]-'0')==test.end())
           {
               test.insert(board[i][colum]-'0');
           }
            else
            {
               return false;
           }
        }
        
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        /*check row & colum*/
        for(int i = 0; i < 9; ++i)
        {
            if(!isValidRow(board,i)||!isValidColum(board,i))
            {
                cout<<i<<endl;
                return false;
            }
        }
                
        /*check block*/
        for(int i = 0;i < 9; i += 3)
        {
            for(int j = 0;j < 9; j += 3)
            {
                if(!isValidBlock(board,i,j))
                {
                    cout<<i<<j<<endl;
                    return false;
                }
            }
        }
        
        return true;
    }
};