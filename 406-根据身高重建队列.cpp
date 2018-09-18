class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        //先按身高排序，然后插入到相应位置上
        vector<pair<int, int>> result;
        sort(people.begin(), people.end(), [](pair<int, int> a, pair<int, int> b)
             {
                 return a.first > b.first || (a.first == b.first && a.second < b.second);
             });
        for(auto p : people)
        {
            result.insert(result.begin() + p.second, p);//注意迭代器
        }
        return result;
    }
};