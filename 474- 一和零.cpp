static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        if(m == 0 && n == 0)
            return 0;
        //dp[i][j]表示用i个0和j个1可以拼出的字符串的最大数量
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(auto s : strs){
            //分别统计s中0和1的个数
            int cnt0 = 0, cnt1 = 0;
            for(auto c : s){
                if(c == '0')
                    cnt0++;
                else
                    cnt1++;
            }
            for(int i=m;i>=cnt0;i--)
                for(int j=n;j>=cnt1;j--)
                    dp[i][j] = max(dp[i][j], dp[i-cnt0][j-cnt1] + 1);
        }
        return dp[m][n];
    }
};