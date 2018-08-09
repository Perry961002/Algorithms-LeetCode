static const auto ban_io_sync = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int minCut(string s) {
        if(s.size() < 2 )
            return 0;
        int len = s.size();  //字符串长度
        vector<vector<int>> dp(len,vector<int>(len,0) );  //dp[i][j]表示从i位置到j位置是不是回文串
        vector<int> cut(len + 1,0);   //cut[i]表示从i位置往后的最少分割数
        for(int i = len-1;i>=0;i--)   //从后向前构造
        {
            cut[i] = len;
            for(int j = i;j<len;j++)
            {
                //状态转移方程： dp[i][j] = s[i] == s[j] && ((j - i) <= 1 || dp[i + 1][j - 1])
                //i和j重合，或者相邻，或者i,j位置之间也是回文串
                if((s[i] == s[j]) && ( (j - i) <= 1 || dp[i + 1][j - 1] == 1))
                {
                    dp[i][j] = 1;
                    cut[i] = min(cut[j + 1] + 1, cut[i]);   //cut[i] = min(cut[j]) , 1 <= j <len  if dp[i][j] == 1;
                }
            }
        }
        return cut[0] - 1;  //去出最后一个字符后的分割
    }
};