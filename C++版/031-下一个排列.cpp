class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();  //长度
        int i = len-2;  //寻找第一个降序的数
        int j = len-1;  //寻找第一个比降序的数大的数
        while( i>=0&&nums[i]>=nums[i+1] ) --i;  //寻找第一个降序的数
        if(i>=0)
        {
            while( nums[j]<= nums[i]) --j;    //寻找第一个大于nums[i]的数
            swap(nums[i],nums[j]);    //交换这两个数
        }
        reverse( nums.begin()+ i+ 1, nums.end() );   //交换之后nums[i+1]到最后满足降序，把他们倒序
    }
};