class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //动态规划
        //dp[i] == true表示从开始位置到i存在满足要求的拆分
        /*
        if(s == "")  //边界情况
            return true;
        string news = '0' + s;  //加上0，这样dp[0] = true;
        vector<bool> dp(news.size());
        dp[0] = true;
        //为字典建hash表
        unordered_map<string, int> book;
        for(auto word:wordDict)
            book[word]++;
        for(int i=1; i<news.size(); ++i)
        {
            for(int j=0;j<i;++j)
            {
                //状态转移方程
                if((dp[j] == true) && book.find( news.substr(j+1,i-j)) != book.end()) //j位置时满足要求，并且j到i之间的字符也是字典中的
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[news.size()-1];
        */
        //对for循环进行优化，按单词遍历
        vector<bool> dp(s.size(),false);
        for(int i=0;i<s.size();i++)
        {
            for(auto &p :wordDict)
            {
                //0到i正好是单词，或者0到j之间是单词并且j+1到i之间也是单词
                if((i>p.size()-1 && s.substr(i-p.size()+1,p.size())==p && dp[i-p.size()]) || (i==p.size()-1 && s.substr(0,p.size())==p))
                {
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[s.size()-1];
    }
};