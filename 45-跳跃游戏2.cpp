class Solution {
public:
    /*
    *贪心法
    */
    int jump(vector<int>& nums) {
        int index = 0 ,maxLen = 0 ,count = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(i>index)   //当前位置超过了覆盖的下标
            {
                index = maxLen;  //覆盖下标更新到最远位置
                count++;   //步数加一
            }
            maxLen = max( maxLen , i+nums[i] );
        }
        return count;
    }
};