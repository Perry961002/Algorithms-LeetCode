class Solution {
public:
    /*深度搜索寻找递增子序列
    *res为结果集合,因为要求不重复,所以用set
    *nums是被寻找的数组
    *lastMax记录上次的最大数字
    *index为下标
    */
    void dfs(set<vector<int>>& res, vector<int>& nums, vector<int>& ans, int lastMax, int index){
        if(ans.size() > 1)
            res.insert(ans);
        //结束条件
        if(index == nums.size())
            return;
        //从下一个位置开始深搜
        for(int i=index+1;i<nums.size();i++){
            //满足递增条件
            if(nums[i] >= lastMax){
                ans.push_back(nums[i]);
                dfs(res, nums, ans, nums[i], i);
                ans.pop_back();//回溯
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        if(nums.size() < 2)
            return {};
        set<vector<int>> tempRes;
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(tempRes, nums, tmp, -101, -1);
        for(auto it : tempRes)
            res.push_back(it);
        return res;
    }
};