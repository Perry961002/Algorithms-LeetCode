class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        if( N >= 0 && N <= 9)
            return N;
        string nums = to_string(N);
        /**
        *贪心算法：
        *从右向左遍历,如果遇到nums[i] < nums[i-1]即递减时,将nums[i-1] 减 1,同时后面的数都置为9
        */
        int begin = nums.size();//记录开始置为9的位置
        for(int i=nums.size()-1;i>0;i--){
            //递减
            if(nums[i-1] > nums[i]){
                nums[i-1]--;
                begin = i;
            }
        }
        for(int i=begin;i<nums.size();i++)
             nums[i] = '9';
        return stoi(nums);
    }
};