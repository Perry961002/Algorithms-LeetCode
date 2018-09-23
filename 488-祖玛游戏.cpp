class Solution {
public:
    /*消除符合条件的小球*/
    string clearBoard(string board)
    {
        for(int start=0, end=0;end<=board.size();end++)
        {
            if(end < board.size() && board[end] == board[start])
                continue;
            if(end - start >= 3)
                {
            	    cout<<end<<endl;
            	    return clearBoard(board.substr(0, start) + board.substr(end));
                }
            else
                start = end;
        }
        return board;
    }
    /*深度搜索*/
    int playGame(string board, unordered_map<char, int>& m)
    {
        board = clearBoard(board);
        //board已经清楚完,最少的移除球数为0
        if(board.empty())
            return 0;
        int minNeed = INT_MAX, start = 0;
        //头尾都可以加入小球
        for(int i=0;i<=board.size();i++)
        {
            if(i < board.size() && board[i] == board[start])
                continue;
            //需要添加的小球数
            int need = 3 - (i - start);
            if(m[board[start]] >= need)
            {
                m[board[start]] -= need;
                //下面需要添加最少的球数
                int nextMin = playGame(board.substr(0, start) + board.substr(i), m);
                if(nextMin != INT_MAX)
                    minNeed = min(minNeed, nextMin + need);
                m[board[start]] += need;//回溯
            }
            start = i;
        }
        return minNeed;
    }
    int findMinStep(string board, string hand) {
        unordered_map<char, int> handMap;
        for(char c : hand)
            handMap[c] ++;
        int result = playGame(board, handMap);
        return result == INT_MAX ? -1 : result;
    }
};