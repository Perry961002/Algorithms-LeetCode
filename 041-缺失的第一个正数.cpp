class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       sort(nums.begin(),nums.end());  //先排序
        int result = 1;  //结果初始化为1
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<1) continue;  //找到第一个正数
            if(nums[i]==nums[i-1]) continue;  //数组中相同的不看
            if(nums[i]==result)
            {
                result++;  //下一个没有找到的正数
            }
            else
                break;
        }
        return result;
        
    }
};