class Solution {
public:
    bool check(int k,vector<int> rec)  //rec里存放的每层皇后所在的位置
    {
        int i;
        for(i=0;i<k;i++)
            if( rec[i] == rec[k] || ( (k-i) == abs(rec[i]-rec[k]) ) )  //皇后在列或对角线上有冲突
                return false;
        return true;
    }
    void dfs(int k,int n,vector<int> &rec,vector<vector<string>> &result)  //rec里存放的每层皇后所在的位置，k是深搜变量
    {
        if( k==n )  //深搜完
        {
            vector<string> solve;  //每层的情况
            string s;
            int i,j;
            for(i=0;i<n;i++)
            {
                s="";  //s初始化
                for(j=0;j<rec[i];j++)
                    s +='.';
                s +='Q';
                for(j=j+1;j<n;j++)
                    s +='.';
                solve.push_back(s);
            }
            result.push_back(solve);
            return;
        }
        else
        {
            int i;
            for(i=0;i<n;i++)
            {
                rec[k] = i;
                if(check(k,rec))
                    dfs(k+1,n,rec,result);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> rec(n,-1);
        vector<vector<string>> result;  //存放最后结果
        dfs(0,n,rec,result);
        return result;
    }
};