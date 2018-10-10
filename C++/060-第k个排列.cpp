class Solution {
public:
    int fact[10] = {1,1,2,6,24,120,720,5040,40320,362880};   //0到10的阶乘
    string getPermutation(int n, int k) {
        string result;
        vector<int> nums(n);  //存放1到n
        for(int i = 0; i < n; i ++)
            nums[i] = i + 1;
        while(n)
        {
            int max = (k-1) / fact[n-1];
            result += (nums[max] + '0');   //确定最高位
            k -= max * fact[n - 1];
            for(int i = max + 1; i < n; i++)   //将数组nums中比max大的数提前一位
                nums[i - 1] = nums[i];
            nums.pop_back();
            n --;
        }
        return result;
    }
};