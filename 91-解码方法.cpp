class Solution {
public:
    int numDecodings(string s) {
        if( s.empty() || s[0]=='0') return 0;   //字符串为空，或者第一个是0
        int len = s.size();  //s的长度
        vector<int> dp(len+1,0); dp[0] = 1;  //dp数组，dp[i]表示第i个位置上的方法数
        s = '0' + s;   //补充一个0
        for(int i=1;i<=len;i++)
        {
           dp[i] = (s[i] == '0')?0:dp[i-1];   //s不是0的话，说明可以加上前一个方法数
            if( i>1 && ( s[i-1] == '1' || ( s[i-1] == '2' && s[i] <= '6' ) ) )  //当前数字可以和之前一个组成有效编码
                dp[i] += dp[i-2];     //加上2个字符长度编码之前的方法书
        }
        return dp.back();
    }
};