class Solution {
public:
    /*
    *动态规划，记录前位置的最大值和最小值
    */
    int maxProduct(vector<int>& nums) {
        int maxpro = nums[0] , minpro = nums[0] , result = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            int tempmax = maxpro , tempmin = minpro;
            maxpro = max( nums[i] , max( tempmax*nums[i] , tempmin*nums[i] ) );  //乘积可以是一个数，可以是前面的最值乘上本身之后的，考虑负数
            minpro = min( nums[i] , min( tempmax*nums[i] , tempmin*nums[i] ) );
            result = max( result ,maxpro );
        }
        return result;
    }
};