static const auto ban_io_sync = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int mid = 0;
        while(left < right)
        {
            mid = (left + right) / 2;
            if(nums[mid] < nums[mid + 1])
                left = mid + 1;  //mid + 1可能是峰
            else
                right = mid;
        }
        return left;
    }
};