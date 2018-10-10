class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> rec;   //解集
        vector<int> hashmap(nums.size()+1);   //构造哈希表
        for(int i=0;i<nums.size();i++)
        {
            hashmap[nums[i]]++;
            if(hashmap[nums[i]]>1)
                rec.push_back(nums[i]);
        }
        return rec;
    }
};