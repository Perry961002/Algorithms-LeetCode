class Solution {
public:
    int minDistance(string word1, string word2) {
        //因为只有删除操作，所以只需要求出两个字符串的最长公共子序列即可
        int l1 = word1.size(), l2 = word2.size();
        vector<vector<int>> dp(l1+1,vector<int>(l2+1, 0));//dp[i][j]表示word1的前i个字符和word2的前j个字符前的LCS
        for(int i=0;i<=l1;i++)
            for(int j=0;j<=l2;j++)
            {
                if(i == 0 || j == 0)
                    continue;
                else
                {
                    if(word1[i-1] == word2[j-1])
                        dp[i][j] = dp[i-1][j-1] + 1;
                    else
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        return l1 + l2 - dp[l1][l2] * 2;
    }
};