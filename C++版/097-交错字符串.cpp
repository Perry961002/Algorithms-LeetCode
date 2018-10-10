class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        //首先想了怎么把s1和s2交错起来：
        //把s1和s2前面加一个空字符，然后展开成二维数组
        //s3就是从左上角开始走到右下角只能向下或者向右
        //向下表示把s1的字符加入s3，向右表示把s2的字符加入s3
        //所以判断s3是不是交错字符串只要比较是不是s1或者s2的字符就行
        int l1 = s1.size(), l2 = s2.size();
        if(l1 + l2 != s3.size())
            return false;
        vector<vector<bool>> dp(l1 + 1, vector<bool>(l2 + 1) );
        for(int i = 0;i<=l1;i++)
        {
            for(int j = 0;j<=l2;j++)
            {
                if(i == 0 && j == 0)
                    dp[i][j] = true;
                else if(i == 0)  //第0行只能向右
                    dp[i][j] = dp[i][j-1] && (s2[j-1] == s3[j-1]);
                else if(j == 0)  ////第0列只能向下
                    dp[i][j] = dp[i-1][j] && (s1[i-1] == s3[i-1]);
                else  //每个位置可能从左边或者上边两个方向过来
                    dp[i][j] = (dp[i][j-1] && (s2[j-1] == s3[i+j-1])) || (dp[i-1][j] && (s1[i-1] == s3[i+j-1]));
            }
        }
        return dp[l1][l2];
    }
};