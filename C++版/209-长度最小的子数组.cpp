static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        //采用滑动窗口，设置左右指针
        //右端不停向右直到窗口中的和>=s,记录最小窗口的大小
        //左端口向右直到窗口中的和<s，记录最小窗口的大小
        int len = nums.size();
        if(len == 0)
            return 0;
        int minlen = len + 1;  //最小窗口大小
        int left = 0, right = -1;  //窗口左右端口
        int sum = 0;  //窗口数字的和
        while(right < len)
        {
            //右端不停向右直到窗口中的和>=s,记录最小窗口的大小
            while(sum < s && right < len)
                sum += nums[++right];
            if(sum >= s)
            {
                minlen = min(minlen, right - left + 1);
                sum -= nums[left++];
            }
        }
        return minlen > len ? 0 : minlen;
    }
};