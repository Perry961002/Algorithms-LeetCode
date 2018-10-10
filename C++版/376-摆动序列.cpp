static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        if(len < 2)
            return len;
        //up[i]和down[i]分别记录到第i个元素为止以上升和下降结束的最长摆动序列的长度
        vector<int> up(len, 0), down(len, 0);
        up[0] = down[0] = 1;
        for(int i=1;i<len;i++)
        {
            if(nums[i] > nums[i-1])  //一个上升
            {
                up[i] = down[i-1] + 1;  //上升前一个应该是下降的
                down[i] = down[i-1];
            }
            else if(nums[i] < nums[i-1])  //一个下降
            {
                down[i] = up[i-1] + 1;  //下降前一个应该是上升的
                up[i] = up[i-1];
            }
            else  //持平的，不变
            {
                up[i] = up[i-1];
                down[i] = down[i-1];
            }
        }
        return max(up[len-1], down[len-1]);
    }
};