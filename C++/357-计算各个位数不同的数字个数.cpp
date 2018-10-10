class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0)
            return 1;
        vector<int> dp(n + 1);   //dp[i] 表示i位数满足各位数字都不同的个数
        int num = 0;
        for(int i=1;i<=n;i++)
        {
            if(i == 1)
                dp[i] = 10;  //一位数有10种情况
            else if(i == 2)
                dp[i] = 9 * 9;//两位数有9 * 9，第一位从1到9选一个，第二位从0到9中选和第一位不一样的
            else
                dp[i] = dp[i - 1] * (11 - i);
            num += dp[i];
        }
        return num;
    }
};