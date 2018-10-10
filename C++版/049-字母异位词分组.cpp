class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;   //结果
        unordered_map<string,vector<string>> rec;  //排序后的词作为键值
        for(int i=0;i<strs.size();i++)
        {
            string str = strs[i];
            sort(str.begin(),str.end());  //对单词按字典序排序
            rec[str].push_back(strs[i]);
        }
        for(auto i:rec)   //auto是智能指针
        {
            result.push_back(i.second);
        }
        return result;
    }
};