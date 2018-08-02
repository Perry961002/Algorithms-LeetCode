class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;
        int maxprofit = 0;
        vector<int> first(prices.size(), 0);  //first[i]表示从0到i的最优买卖值
        vector<int> second(prices.size(), 0); //second[i]表示从i到最后的最差买卖值(高买低卖，为负)
        int minprice = prices[0];   //记录最小的买入价格
        for(int i = 1;i < prices.size();i++)
        {
            minprice = min(minprice, prices[i]);
            first[i] = max(first[i-1], prices[i] - minprice);
        }
        int maxprice = prices[prices.size()-1];
        for(int i = prices.size()-2;i >= 0;i--)
        {
            maxprice = max(maxprice, prices[i]);
            second[i] = min(second[i+1], prices[i] - maxprice);
            maxprofit = max(maxprofit, first[i] - second[i]);
        }
        return maxprofit;
    }
};