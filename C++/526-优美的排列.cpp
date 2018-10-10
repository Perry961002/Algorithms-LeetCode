class Solution {
public:
    //深度搜索, 回溯
    //用数组n去尝试数组中每一个他可以放置的位置，然后深搜下一个数字
    //因为1可以整除每一个正整数，所以从N开始深搜
    void dfs(int num, vector<bool>& visited, int &all)
    {
        if(num == 1)
        {
            all ++;
            return;
        }
        for(int i=1;i<visited.size();i++)
        {
            if(visited[i] == false && (i % num == 0 || num % i == 0))
            {
                visited[i] = true;//num被放在i位置
                dfs(num-1, visited, all);
                visited[i] = false;//回溯
            }
        }
    }
    int countArrangement(int N) {
        vector<bool> visited(N+1, false);
        int result  = 0;
        dfs(N, visited, result);
        return result;
    }
};