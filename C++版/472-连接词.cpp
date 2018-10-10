class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());//因为unordered_set的插入和查找效率很高
        vector<string> res;
        for(auto w : words)
        {
            int len  = w.size();
            vector<bool> dp(len + 1, false);//dp[i]表示前i个字符可以满足条件
            dp[0] = true;//空字符总是有效的
            for(int i=0;i<len;i++)
            {
                if(dp[i] == false)//保证从上次已经匹配的地方开始
                    continue;
                for(int j=i+1;j<=len;j++)
                    if(j - i < len && dict.count(w.substr(i, j - i)))//因为j-i<len,所以不会匹配到w本身
                        dp[j] = true;
                if(dp[len])
                {
                    res.push_back(w);
                    break;//提前停止
                }
            }
        }
        return res;
    }
};