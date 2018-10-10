class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> res;
        int cur=0, cur_X, cur_H =-1,  len = buildings.size();
        priority_queue< pair<int, int>> liveBlg; // 第一个元素是高度buindings[k][2]，第二个元素是结束点的x坐标buildings[k][1]
        while(cur<len || !liveBlg.empty())
        { 
            // 如果是最开始处理建筑，或者出现建筑物不连续的情况（即对于上面第4个建筑和第3个建筑分开的情况）
            cur_X = liveBlg.empty()? buildings[cur][0]:liveBlg.top().second; // 最高建筑的结束点
 
            if(cur>=len || buildings[cur][0] > cur_X)
            {
                //将结束时间小于等于最高建筑结束点的哪些建筑物从优先队列中弹出
                while(!liveBlg.empty() && ( liveBlg.top().second <= cur_X) ) liveBlg.pop();
            }
            else
            { 
                //如果当前遍历到的建筑物在最高的建筑物结束之前开始，那么处理当前的建筑物
                cur_X = buildings[cur][0];
                while(cur<len && buildings[cur][0]== cur_X)  // 处理所有在同一点开始的建筑物
                {  // just push them in the queue
                    liveBlg.push(make_pair(buildings[cur][2], buildings[cur][1]));
                    cur++;
                }
            }
            cur_H = liveBlg.empty()?0:liveBlg.top().first; // 输出最顶端的建筑物的高度
            if(res.empty() || (res.back().second != cur_H) ) res.push_back(make_pair(cur_X, cur_H));
        }
        return res;

    }
};