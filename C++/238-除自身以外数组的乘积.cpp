class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1)
            return nums;
        vector<int> result(len, 1);
        for(int i=1;i<len;i++)
            result[i] = result[i-1] * nums[i-1];  //先计算i位置左边数的成绩
        int temp = 1;//记录i位置右边数的乘积
        for(int i=len-1;i>=0;i--)
        {
            result[i] *= temp;
            temp *= nums[i];
        }
        return result;
    }
};