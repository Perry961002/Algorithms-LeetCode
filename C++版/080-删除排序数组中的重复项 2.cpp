static const auto ban_io_sync = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 3)   //长度小于3，直接输出
            return nums.size();
        int length = 1;  //新长度,同时记录上一个符合要求的位置
        int count = 1;  //重复次数
        int target = nums[0];  //前一个不重复的数字
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] == target)  //有重复的数字
            {
                count++;  //重复次数加1
                if(count <= 2)  //重复次数小于3
                {
                    length++;
                    nums[length - 1] = nums[i];
                }
            }
            else   //和前一个没有重复
            {
                target = nums[i];
                count = 1;
                length++;
                nums[length - 1] = nums[i];
            }
        }
        return length;
    }
};