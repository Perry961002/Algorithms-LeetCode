class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        //disjoint-set data structure不相交集合
        vector<int> dst(N+1, 0);//dst[i]表示i所在的并查集
        //初始化
        for(int i=1;i<=N;i++){
            dst[i] = i;
        }
        for(auto edge : edges){
            int u = edge[0];//集合的代表
            int v = edge[1];
            //u和v已经在并查集中,就是多余的边,输出他
            if(dst[u] == dst[v])
                return edge;
            //将之前v的并查集并入u的并查集中
            int needUpdate = dst[v];
            for(int i=1;i<=N;i++){
                if(dst[i] == needUpdate){
                    dst[i] = dst[u];
                }
            }
        }
        
    }
};