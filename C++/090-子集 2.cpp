class Solution {
public:
    /**
    *假设a1,a2,...,an-1没有重复元素,现在考虑an 和 an-1相等
    *那么an只能插入已经出现过an-1的子集,否则会有重复子集,按照上述原则最后的子集一定没有重复
    */
    void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int>& subSet, int index){
        //所有元素都考虑过一次
        if(index == nums.size()){
            res.push_back(subSet);
            return;
        }
        int firstSame = index;//index之前第一个重复的元素下标
        while(firstSame >= 0 && nums[firstSame] == nums[index])
            firstSame --;
        firstSame ++;
        int k = index - firstSame;//重复的次数
        //只能插入之前已经插入重复元素的子集
        if(k == 0 || (subSet.size() >= k && subSet[subSet.size() - k] == nums[index]) ){
            subSet.push_back(nums[index]);
            dfs(res, nums, subSet, index + 1);
            subSet.pop_back();
        }
        
        //不选这个元素
        dfs(res, nums, subSet, index + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subSet;
        //先排序
        sort(nums.begin(), nums.end());
        dfs(res, nums, subSet, 0);
        return res;
    }
};