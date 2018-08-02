static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int differ = 0;
        for(int i = 1;i<prices.size();i++)
        {
            differ = prices[i] - prices[i-1];
            maxprofit += (differ > 0) ? differ : 0;
        }
        return maxprofit;
    }
};