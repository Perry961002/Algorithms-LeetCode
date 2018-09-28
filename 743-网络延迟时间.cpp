class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> dist(N + 1, INT_MAX);
        dist[K] = 0;
        for (int i = 0; i < N; i++)
        {
            for (auto edge : times)
            {
                int from = edge[0], to = edge[1], value = edge[2];
                if (dist[from] != INT_MAX && dist[to] > dist[from] + value)
                    dist[to] = dist[from] + value;
            }
        }

        int maxTime = 0;
        for(int i=1;i<=N;i++)
            maxTime = max(maxTime, dist[i]);
        return maxTime == INT_MAX ? -1 : maxTime;
    }
};