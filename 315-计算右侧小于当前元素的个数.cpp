class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> sortnums;
        vector<int> result(nums.size());
        for(int i=nums.size()-1;i>=0;i--)
        {
            auto index = lower_bound(sortnums.begin(), sortnums.end(), nums[i]);//二分查找
            result[i] = index - sortnums.begin();
            sortnums.insert(index, nums[i]);
        }
        return result;
    }
};