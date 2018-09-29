static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();
class Solution {
private:
    int M = 1000000007;
public:
    int checkRecord(int n) {
        //先考虑只有"P" 和"L"的情况,令dp[i]表示长度为i的符合这个要求的个数
        //按结尾分有3中情况,分别为"P", "PL","PLL",那么转移方程为dp[i] = dp[i-1] + dp[i-2] + dp[i-3]
        //添加"A"的话,就是考虑对n-1的情况添加一个,那么字符串会被分成两部分,应该是sum(dp[i] * dp[n-1-i]),i = 0, 1, ..., n-1
        if(n == 1)
            return 3;
        if(n == 2)
            return 8;
        vector<long> dp(n + 1, 0);
        dp[0] = 1; dp[1] = 2; dp[2] = 4;//初始化
        //状态转移方程
        for(int i=3;i<=n;i++){
            dp[i] = ((dp[i-1] + dp[i-2]) % M + dp[i-3] ) % M;  
        }
        long res = dp[n];
        //开始添加"A"
        for(int i=0;i<n;i++){
            res = (res + (dp[i] * dp[n-1-i]) % M ) % M;
        }
        return res;
    }
};