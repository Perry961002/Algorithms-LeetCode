class Solution {
public:
    string frequencySort(string s) {
        string res = "";
        priority_queue<pair<int, char>> q;//堆排序,大根堆
        unordered_map<char, int> m;
        for(char c : s)
            m[c] ++;
        for(auto a : m)
            q.push({a.second, a.first});
        while(!q.empty())
        {
            auto t = q.top();
            q.pop();
            res.append(t.first, t.second);
        }
        return res;
    }
};