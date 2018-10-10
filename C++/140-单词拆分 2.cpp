class Solution {
private:
    unordered_map<string, vector<string>> dpHash;//记录s在i位置字串的一个有效拆分
public:
    vector<string> dfs(string s, unordered_set<string>& words)
    {
        //s已经拆分完
        if(dpHash.count(s) > 0)
            return dpHash[s];
        vector<string> res;//记录s的拆分
        //s在字典中出现
        if(words.count(s) > 0)
            res.push_back(s);
        //s整体的情况已考虑了
        for(int end=0;end<s.size();end++)
        {
            string before = s.substr(0, end);//取出前一段子串
            //子串是字典中的单词
            if(words.count(before) > 0)
            {
                //后半部分的情况
                vector<string> after = dfs(s.substr(end), words);
                for(auto str : after)
                    res.push_back(before + " " + str);
            }
        }
        dpHash[s] = res;//装入s的可拆分结果
        return res;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        return dfs(s, words);
    }
};