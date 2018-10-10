class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int len1 = s1.size(), len2 = s2.size();
        //dp[i][j]表示s1的前i个字符和s2的前j个字符的最小ASCII删除和
        //考虑dp[i][j]的3个前驱状态
        /**
        *dp[i-1][j],一样到dp[i][j]需要多考虑一个s1的字符,而s2不用,所以删除s1[i]
        *dp[i][j-1],一样到dp[i][j]需要多考虑一个s2的字符,而s2不用,所以删除s2[i]
        **dp[i-1][j-1],需要考虑s1[i]和s2[j],如果s1[i] == s2[j],那么不需要删除,如果不等,则删除s1[i] + s2[i]
        */
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        for(int i=0;i<=len1;i++){
            for(int j=0;j<=len2;j++){
                if(i == 0 && j > 0){
                    dp[i][j] = dp[i][j-1] + s2[j-1];
                }
                else if(j == 0 && i > 0){
                    dp[i][j] = dp[i-1][j] + s1[i-1];
                }
                else if(i > 0 && j > 0){
                    int diff = (s1[i-1] == s2[j-1]) ? 0 : s1[i-1] + s2[j-1];
                    dp[i][j] = min(min(dp[i][j-1] + s2[j-1], dp[i-1][j] + s1[i-1]), dp[i-1][j-1] + diff);
                }
            }
        }
        return dp[len1][len2];
    }
};