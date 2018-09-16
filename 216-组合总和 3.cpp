class Solution {
public:
    //深度搜索+回溯
    void dfs(int n, int k, int start, vector<int> &ans, vector<vector<int>> &result)
    {
        if(n < 0)
            return;
        if(n == 0 && ans.size() == k)
            result.push_back(ans);
        for(int i = start;i<=9;i++)
        {
            ans.push_back(i);
            dfs(n-i,k,i+1,ans,result);
            ans.pop_back();//回溯
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ans;
        vector<vector<int>> result;
        dfs(n,k,1,ans,result);
        return result;
    }
};