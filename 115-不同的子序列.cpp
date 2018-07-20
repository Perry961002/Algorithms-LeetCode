class Solution {
public:
    /*
    *动态规划法：
    *dp[i][j]代表由s的前i个字符串和t的前j个多少种匹配
    *dp[i][0] = 1。s的前i个字符串中都包含一个”“子串
    *dp[i][j] = dp[i-1][j]。最基本的关系
    *dp[i][j] += dp[i-1][j-1]. if (s[i-1] == t[j-1])
    */
    int numDistinct(string s, string t) {
        if(s.empty() || t.empty() || s.size() < t.size())
            return 0;
        int s_len = s.size() , t_len = t.size();
        vector<vector<int>> dp(s_len + 1, vector<int>(t_len + 1, 0));  //p[i][j]代表由s的前i个字符串和t的前j个多少种匹配
        for(int i = 0;i<=s_len;i++)   //dp[i][0] = 1。s的前i个字符串中都包含一个”“子串
            dp[i][0] = 1;
        for(int i = 1;i<=s_len;i++)
            for(int j = 1;j<=t_len;j++)
            {
                dp[i][j] = dp[i-1][j];
                if(s[i-1] == t[j-1])
                    dp[i][j] += dp[i-1][j-1];   //dp[i][j] += dp[i-1][j-1]. if (s[i-1] == t[j-1]),注意下标
            }
        return dp[s_len][t_len];
    }
};