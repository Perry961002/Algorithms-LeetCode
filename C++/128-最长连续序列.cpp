static const auto ban_io_sync = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    /*
    *简单的想法就是先排序在找连续序列，但复杂度不符要求
    *遍历到某一个数时，寻找他相邻的两个数在不在，最后将两个方向上统计的个数相加即可
    *先建立hash表，遇到之前遍历过的数跳过
    */
    int longestConsecutive(vector<int>& nums) {
        int len = nums.size();
        if(len < 2)
            return len;
        int maxlen = 0;
        unordered_map<int,bool> map;
        for(int i=0;i<len;i++)
            map[nums[i]] = false;  //预先建立hash表
        for(int i=0;i<len;i++)
        {
            if(!map[nums[i]])  //之前没有被遍历过
            {
                map[nums[i]] = true;
                int left = nums[i] - 1;  //左边与相邻的数
                int llen = 0;  //左边的个数
                while(map.count(left) != 0 && !map[left])  //左边应该相邻的数存在且没有访问过
                {
                    map[left] = true;
                    left--;  //找的下一个数
                    llen++;
                }
                int right = nums[i] + 1;  //右边与相邻的数
                int rlen = 0;  //右边的个数
                while(map.count(right) != 0 && !map[right])  //右边应该相邻的数存在且没有访问过
                {
                    map[right] = true;
                    right++;  //找的下一个数
                    rlen++;
                }
                maxlen = max(maxlen, llen + rlen + 1);
            }
        }
        return maxlen;
    }
};