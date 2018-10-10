class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        //找一条走过每条边一次的路径，即找一条欧拉回路
        vector<string> result;  //结果集
        unordered_map<string, multiset<string>> map;  //multiset容器在插入时可以对元素按字典序排序
        for(auto t : tickets)
            map[t.first].insert(t.second);
        string from = "JFK";
        stack<string> s;
        s.push(from);
        //开始dfs
        while(!s.empty())
        {
            from = s.top();
            if(map[from].empty())  //当前节点的下一个被访问了
            {
                result.push_back(from);
                s.pop();
            }
            else
            {
                s.push(*(map[from].begin()));  //from的下一个邻接点,因为begin()是顶端迭代器，要用指针
                map[from].erase(map[from].begin());  //删除他，表示访问过
            }
        }
        reverse(result.begin(),result.end());  //因为dfs具有回溯性质，所以要翻转
        return result;
    }
};