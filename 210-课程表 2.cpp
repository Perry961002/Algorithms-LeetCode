static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        //对这个图进行拓扑排序，判断有没有环
        //pair<to,from>
        vector<int> result;
        vector<vector<int>> Adj(numCourses);  //邻接矩阵
        vector<int> indegree(numCourses, 0);  //每个节点的入度个数，即每门课的先修课程个数
        int numpair = prerequisites.size();
        //构造indegree和Adj
        for(auto p : prerequisites)
        {
            indegree[p.first] ++;  //第二个参数表示入度
            Adj[p.second].push_back(p.first); //邻接表
        }
        queue<int> res;  //存放入度为0的节点，如果图可以进行拓扑排序，队列中的序列就是一种可行的拓扑序列
        //现将开始时入度为0的节点入队
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i] == 0)
                res.push(i);
        }
        //现将队中元素出队，把元素的出度边删除，并更新他的出度点的入度信息，如果有新的入度为0的节点就加入队列
        while(!res.empty())
        {
            int from = res.front();
            res.pop();
            result.push_back(from);
            for(auto to : Adj[from])  //遍历当前节点的邻接节点
            {
                if(indegree[to] == 1)  //to的入度为1，说明to在更新信息后将变成入度为0的点，提前放入
                    res.push(to);
                indegree[to] --;  //更新入度信息
            }
        }
        if(result.size() == numCourses)
            return result;
        else
            return {};
    }
};