class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        //最长递增子序列的升级版，是二维的，可以先按宽度排序这样就降成一维的了，再使用和300题一样的方法即可
        vector<int> dp;
        sort(envelopes.begin(),envelopes.end(),[](const pair<int,int>& a,pair<int,int>& b)
             {
                 if(a.first == b.first)  //如果宽相等的话就按高的降序排序，如果不这样的话按高度求最长递增时后面就可以容纳前面的
                     return a.second > b.second;
                 return a.first < b.first;
             });
        for(auto Elopes : envelopes)
        {
            if(dp.empty() || Elopes.second > dp.back())   //比dp末尾的大，说明满足递增条件
                dp.push_back(Elopes.second);
            else   //比dp末尾的小
            {
                int left = 0, right = dp.size() - 1;
                int mid = 0;
                //在dp中找第一个比Elopes大的，替换他
                while(left < right)
                {
                    mid = (left + right) / 2;
                    if(dp[mid] < Elopes.second)
                        left = mid + 1;
                    else
                        right = mid;
                }
                dp[left] = Elopes.second;
            }
        }
        return dp.size();
    }
};