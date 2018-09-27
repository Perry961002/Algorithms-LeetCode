class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty())
            return 0;
        if(k >= prices.size() / 2){
            int res = 0;
            for(int i=1;i<prices.size();i++){
                if(prices[i] - prices[i-1] > 0)
                    res += prices[i] - prices[i-1];
            }
            return res;
        }
        //local[i][j]为在到达第i天时最多可进行j次交易并且最后一次交易在最后一天卖出的最大利润
        vector<int> local(k+1, 0);
        //定义global[i][j]为在到达第i天时最多可进行j次交易的最大利润
        vector<int> global(k+1, 0);
        /*
        *local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff)
        *global[i][j] = max(local[i][j], global[i - 1][j])，
        */
        for(int i=1;i<prices.size();i++){
            int diff = prices[i] - prices[i-1];
            for(int j=k;j>=1;j--){
                local[j] = max(global[j-1] + max(diff, 0), local[j] + diff);
                global[j] = max(local[j], global[j]);
            }
        }
        return global[k];
    }
};