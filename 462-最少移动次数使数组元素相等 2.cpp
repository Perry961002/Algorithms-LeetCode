static const int __ = []{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        //即求数组中所有数到某个数的距离最小
        //从数学上可知数组的中点就是所求点
        sort(nums.begin(), nums.end());
        int start = 0, end = nums.size() - 1;
        int res = 0;
        while(start < end){
            res += nums[end--] - nums[start++];
        }
        return res;
    }
};