class Solution {
public:
    //两个指针 start, end.  如果nums[end+1] = nums[end]+1, 就移动end指针, 否则, 插入字符串nums[start]->nums[end]
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if(nums.size() < 1)
            return result;
        int start = 0, end = 0;
        while(end < nums.size())
        {
            if( end+1 < nums.size() && nums[end+1] == nums[end]+1)
                end ++;
            else
            {
                if(start == end)
                    result.push_back(to_string(nums[end]));
                else
                {
                    string str = to_string(nums[start]) + "->" + to_string(nums[end]);
                    result.push_back(str);
                }
                end ++;
                start = end;
            }
        }
        return result;
    }
};