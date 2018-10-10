class Solution {
public:
    //前缀树
class Trie {
    public:
        bool isEnd;//结束标志
        Trie* children[26];//节点的孩子,因为只有小写字母,大小可定
        Trie():isEnd(false){
            memset(children, NULL, sizeof(children));//为孩子数组分配空间
        }
    };
    void dfs(vector<vector<char>>& board, Trie* root, string str, int x, int y, vector<string>& res)
    {
        if(!root || board[x][y] == '.')//减枝,当前字符不在前缀树,或者已经扫描过
            return;
        int m = board.size(), n = board[0].size();
        str += board[x][y];
        if(root->isEnd)//找到一个单词
        {
            res.push_back(str);
            root->isEnd = false;//因为路径可能不止一条,防止下次再找到
        }
        char ch = board[x][y];//先复制出来
        board[x][y] = '.';//标记,已经访问过
        //向上
        if(x - 1 >= 0)
            dfs(board, root->children[board[x-1][y] - 'a'], str, x - 1, y, res);
        //向下
        if(x + 1 < m)
            dfs(board, root->children[board[x+1][y] - 'a'], str, x + 1, y, res);
        //向左
        if(y - 1 >= 0)
            dfs(board, root->children[board[x][y-1] - 'a'], str, x, y - 1, res);
        //向右
        if(y + 1 < n)
            dfs(board, root->children[board[x][y+1] - 'a'], str, x, y + 1, res);
        board[x][y] = ch;//回溯
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.empty() || board[0].empty() || words.empty())
            return {};
        Trie* root = new Trie();//把单词放入Trie树
        for(auto word : words)
        {
            Trie* node = root;
            for(auto ch : word)
            {
                if(!node->children[ch - 'a'])
                    node->children[ch - 'a'] = new Trie();
                node = node->children[ch - 'a'];
            }
            node->isEnd = true;//一个单词构造完了
        }
        vector<string> result;
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                dfs(board, root->children[board[i][j] - 'a'], "", i, j, result);
        return result;
    }
};