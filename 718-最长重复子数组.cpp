class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int lenA = A.size(), lenB = B.size();
        //dp[i][j]表示在A的i位置和B的j位置的最长重复子数组
        vector<vector<int>> dp(lenA+1, vector<int>(lenB+1, 0));
        int longest = 0;
        for(int i=1;i<=lenA;i++)
            for(int j=1;j<=lenB;j++){
                if(A[i-1] == B[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                longest = max(longest, dp[i][j]);
            }
        return longest;
    }
};