class Solution {
public:
    //考虑分割点在k位置，则有a1,a2,...,ak-1,ak,ak+1,...an，ak之前的部分设为A1,后面的设为A2
    //当ak扎破之后，ak-1和ak+1变为相邻节点，A1和A2不再独立
    //不妨把ak当做最后一个被踩的气球
    int maxCoins(vector<int>& nums) {
        int n = nums.size()+2;
        vector<int> arr(n);
        for(int i=1;i<nums.size()+1;++i)
            arr[i] = nums[i-1];
        arr[0] = arr[nums.size() + 1] = 1;
        vector<vector<int>> dp(n, vector<int> (n));
        for(int k=2;k<n;++k)
        {
            for(int left = 0;left<n-k;++left)
            {
                int right = left + k;
                for(int i=left+1;i< right; ++i)
                {
                    dp[left][right] = max(dp[left][right],arr[left]*arr[i]*arr[right] + dp[left][i] + dp[i][right]);
                }
            }    
        }
        return dp[0][n-1];

    }
};