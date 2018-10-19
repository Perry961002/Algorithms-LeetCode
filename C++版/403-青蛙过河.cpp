class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, set<int>> dp;
		int u = 0, v = 0, w = 0;
		set<int> st;
		set<int>::iterator it;
		dp[0].insert(1);//从0号开始可以向前跳的步数
		for (int i = 0; i < stones.size(); ++i)
            st.insert(stones[i]);
		for (int i = 0; i < stones.size(); ++i){
			u = stones[i];
			if (dp.find(u) == dp.end())
                continue;
			if (u == stones[stones.size() - 1])
                break;
			for (it = dp[u].begin(); it != dp[u].end(); ++it){
				w = *it;//当前step
				v = u + w;//当前到达的石头的Unit
				if (st.find(v) != st.end() && v > u){
					dp[v].insert(w - 1);
					dp[v].insert(w);
					dp[v].insert(w + 1);
				}
			}
		}
		return dp.find(u) != dp.end() && dp[u].size() > 0;
    }
};