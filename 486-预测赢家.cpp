class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        //记玩家1拿为"+", 玩家2拿为"-"
        //dp[i][j]表示从i位置到j位置两个人结果的差值
        if(nums.size() < 3)
            return true;
        //初始化
        int len = nums.size();
        vector<vector<int>> dp(len, vector<int> (len, 0));
        for(int i=0; i<len; i++)
            dp[i][i] = nums[i];
        for(int i=len-2; i>=0; i--)
            for(int j=i+1; j<len; j++){
                // 如果玩家1拿了nums[i],玩家2则从 i+1 到 j 中挑选对自己最有利的
                // 如果玩家1拿了nums[j],玩家2则从 i 到 j-1 中挑选对自己最有利的
                dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
            }
        return dp[0][len - 1] >= 0;
    }
};