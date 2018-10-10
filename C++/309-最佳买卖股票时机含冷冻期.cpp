class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //给出三个状态S0,S1,S2;
        //S0在买入后进入S1，或者继续等待还是S0;
        //S1时卖出进入S3,或者继续等待
        //S3等待进入S1
        int len = prices.size();
        if(len <= 1)
            return 0;
        vector<int> s0(len, 0);
        vector<int> s1(len, 0);
        vector<int> s2(len, 0);
        s1[0] = -prices[0];
        s0[0] = 0;
        s2[0] = INT_MIN;
        for (int i = 1; i < len; i++)
        {
             s0[i] = max(s0[i - 1], s2[i - 1]);
             s1[i] = max(s1[i - 1], s0[i - 1] - prices[i]);
             s2[i] = s1[i - 1] + prices[i];
        }
        return max(s0[len - 1], s2[len - 1]);
    }
};