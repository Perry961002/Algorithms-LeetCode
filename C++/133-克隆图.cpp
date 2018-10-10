/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
    //存放被访问过的节点, 源节点对应新节点
    unordered_map<UndirectedGraphNode*,UndirectedGraphNode*>  hash;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node)
            return NULL;
        /*
        //BFS
        UndirectedGraphNode* graph = new UndirectedGraphNode(node->label);
        hash[node] = graph;
        queue<UndirectedGraphNode*> q;
        q.push(node);
        while(!q.empty())
        {
            UndirectedGraphNode* cur = q.front();
            q.pop();
            //访问当前节点的所有邻接节点
            for(auto val : cur->neighbors)
            {
                //当前节点没有被访问则加入到图中
                if(hash.find(val) == hash.end())
                {
                    hash[val] = new UndirectedGraphNode(val->label);
                    q.push(val);
                }
                hash[cur]->neighbors.push_back(hash[val]);
            }
        }
        return graph;
        */
        if(hash.count(node)) return hash[node];  //访问过
        hash[node] = new UndirectedGraphNode(node->label);
        //访问当前节点的邻接节点
        for(auto val : node->neighbors)
        {
            //访问这个节点的邻接节点
            hash[node]->neighbors.push_back(cloneGraph(val));
        }
        return hash[node];
    }
};