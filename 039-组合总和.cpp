class Solution {
public:
    /*
    *每次读candidates[i]，如果=target，放入解中，如果<target,放入解中并继续递归(从i位置开始，避免重复)，如果>target,回溯
    */
    void dfs(vector<int> candidates, int target,int start,vector<int> rec,vector<vector<int>>& answer)
    {
        if(target<0)   //>target终止
            return;
        if(target==0)  //rec为一个解，放入解集
        {
            answer.push_back(rec);   //放入解集
            return;
        }
        for(int i=start;i<candidates.size();i++)
        {
            rec.push_back(candidates[i]);    //放入疑似解中
            dfs(candidates,target-candidates[i],i,rec,answer);   //深搜
            rec.pop_back();   //回溯
            
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> rec;
        vector<vector<int>> answer;
        dfs(candidates,target,0,rec,answer);
        return answer;
    }
};