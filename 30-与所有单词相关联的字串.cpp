static const auto _=[](){
    std:ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if(s == "" || words.empty())
            return result;
        int slen = s.size();  //s的长度
        int wordlen = words[0].size(); //单个词的长度
        int wordcount = words.size();  //单词的个数
        int findlen = wordlen * wordcount; //每次应该在s中需要匹配的字符的长度
        //建立hash表
        unordered_map<string, int> book;
        for(auto word : words)
            book[word] ++;
        int i = 0;int a= 0;
        int count;  //记录匹配到的字符的个数
        while(i <= slen - findlen)
        {
            count = 0;
            unordered_map<string, int> temp(book);  //复制一份hash表
            int k = i;
            while(k <= i + findlen)
            {
                string tempword = s.substr(k, wordlen);  //取出一个单位长度的单词
                if(temp.find(tempword) == temp.end())
                {
                    //没有找到单词，说明以i为起点一定找不到一个完全的匹配,从i的下一个位置开始
                    i++;
                    break;
                }
                else  //匹配了一个单词
                {
                    if(temp[tempword] > 0)  //防止在findlen的长度里出现了过度匹配的情况
                    {
                        temp[tempword]--;
                        count++;
                        k += wordlen;  //从下一个单词开始
                    }
                    else  //出现了过度的匹配
                    {
                        i++;
                        break;
                    }
                }
                if(count == wordcount)  //words中的单词都匹配了
                {
                    result.push_back(i);
                    i++;
                    break;
                }
            }
        }
        return result;
    }
};