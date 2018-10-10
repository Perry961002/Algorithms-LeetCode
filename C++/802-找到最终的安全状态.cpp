class Solution {
public:
    //如果从一个节点出发的所有路径都是安全的,那么这个节点就是安全的
    
    //colour[i]表示节点的染色,-1表示未访问,0表示节点不安全,1表示安全
    bool isSafeNode(int node, vector<vector<int>>& graph, vector<int>& colour){
        if(colour[node] != -1)
            return colour[node] == 1;
        colour[node] = 0;//先设为不安全
        for(auto next : graph[node]){
            //只要有一条不安全就结束
            if(!isSafeNode(next, graph, colour))
                return false;
        }
        colour[node] = 1;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int count = graph.size();
        vector<int> colour(count, -1);
        vector<int> res;
        for(int i=0;i<count;i++){
            if(isSafeNode(i, graph, colour))
                res.push_back(i);
        }
        return res;
    }
};