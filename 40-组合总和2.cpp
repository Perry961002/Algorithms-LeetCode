class Solution {
public:
    void dfs(vector<int> candidates, int target,int start,vector<int> rec,vector<vector<int>>& answer)
    {
        if(target<0)   //>target终止
            return;
        else if(target==0)  //rec为一个解，放入解集
        {
            answer.push_back(rec);   //放入解集
            return;
        }
        else
            for(int i=start;i<candidates.size();i++)
            {
                if(i>start&&candidates[i]==candidates[i-1]) continue;    //从重复数字的下一个开始
                rec.push_back(candidates[i]);    //放入疑似解中
                dfs(candidates,target-candidates[i],i+1,rec,answer);   //深搜
                rec.pop_back();   //回溯
            
            }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> rec;
        vector<vector<int>> answer;
        dfs(candidates,target,0,rec,answer);
        return answer;
    }
};