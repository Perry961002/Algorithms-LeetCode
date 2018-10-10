static const auto __ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        //动态规划算法：dp[i][j]表示从i到j可以构成的最长回文子序列的长度
        int len = s.size();
        vector<vector<int>> dp(len, vector<int>(len) );
        for(int i=len-1;i>=0;i--)
        {
            dp[i][i] = 1;  //初始化
            for(int j=i+1;j<len;j++)
            {
                if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1] + 2; //首位数字相等，长度+2
                else
                    dp[i][j]=max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][len-1];
    }
};