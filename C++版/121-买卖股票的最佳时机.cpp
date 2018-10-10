static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;
        int minprice = prices[0]; //最低价格
        int maxprofit = 0;   //最大收益
        for(int i = 1;i < prices.size();i++)
        {
            minprice = min(minprice, prices[i]);
            maxprofit = max(maxprofit, prices[i] - minprice);
        }
        return maxprofit;
    }
};