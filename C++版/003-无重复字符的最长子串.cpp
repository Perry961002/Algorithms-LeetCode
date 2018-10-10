static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        if(len < 2)
            return len;
        vector<int> map(256,-1);  //存放出现的位置
        int maxlen = 0, start = -1;  //最长不重复子串的长度，子串开始的下标
        for(int i=0;i<len;i++)
        {
            if(map[s[i]] > start) //出现重复字符
                start = map[s[i]]; //被重复的字符上一次出现的下标
            map[s[i]] = i;  //不是重复的，记录他
            maxlen = max(maxlen, i - start);
        }
        return maxlen;
    }
};