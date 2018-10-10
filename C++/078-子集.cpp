class Solution {
public:
    //以深搜方法,考虑第i个元素要不要选
    void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int> subSet, int i){
        //所有元素都考虑过一次
        if(i == nums.size()){
            res.push_back(subSet);
            return;
        }
        
        //不选这个元素
        dfs(res, nums, subSet, i+1);
        
        //选这个元素
        subSet.push_back(nums[i]);
        dfs(res, nums, subSet, i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subSet;
        dfs(res, nums, subSet, 0);
        return res;
    }
};