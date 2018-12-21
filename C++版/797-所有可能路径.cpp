class Solution {
public:
    void dfs(int cur, vector<vector<int>>& graph, vector<int> path, vector<vector<int>>& res){
        if(cur == (graph.size() - 1)){
            path.push_back(cur);
            res.push_back(path);
            return;
        }
        //深搜
        for(int next : graph[cur]){
            path.push_back(cur);
            dfs(next, graph, path, res);
            path.pop_back();//回溯
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        vector<vector<int>> res;
        dfs(0, graph, path, res);
        return res;
    }
};