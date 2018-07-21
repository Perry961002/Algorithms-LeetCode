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
    void dfs(int k,int n,vector<int> &rec,int &sum)  //rec里存放的每层皇后所在的位置，k是深搜变量
    {
        if( k==n )  //深搜完
        {
            sum++;
            return;
        }
        else
        {
            int i;
            for(i=0;i<n;i++)
            {
                rec[k] = i;
                if(check(k,rec))
                    dfs(k+1,n,rec,sum);
            }
        }
    }
    int totalNQueens(int n) {
        vector<int> rec(n,-1);
        int sum = 0;  //存放最后结果
        dfs(0,n,rec,sum);
        return sum;
    }
};