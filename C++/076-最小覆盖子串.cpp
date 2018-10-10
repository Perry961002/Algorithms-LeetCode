class Solution {
public:
    string minWindow(string s, string t) {
        //采用滑动窗口法
        if(t.size() > s.size())
            return "";
        string result;
        int left = 0 , count = 0, minlen = s.size() + 1;  //count记录s中出现的t中字符的个数，minlen记录最小覆盖子串长度
        unordered_map<char,int> tmap;  //用hash表记录t的字符
        for(int i = 0;i<t.size();i++)
        {
                tmap[t[i]]++;
        }
        for(int right = 0;right<s.size();right++)
        {
            if(tmap.find(s[right]) != tmap.end())  //s[i]是t中的字符
            {
                tmap[s[right]]--;
                if(tmap[s[right]] >= 0)  //统计已经出现的t的字符时防止重复出现的字符
                    count++;
                while(count == t.size())  //出现了覆盖子串
                {
                    if((right - left + 1) < minlen)  //更新当前的最小覆盖子串信息
                    {
                        minlen = right - left + 1;
                        result = s.substr(left, minlen);
                    }
                    if(tmap.find(s[left]) != tmap.end())   //向右移动窗口的左下标
                    {
                        tmap[s[left]]++;  //重新寻找覆盖子串，更新之前的tmap和count的信息
                        if(tmap[s[left]] > 0)   //tmap[s[left]] > 0说明s中还需要找覆盖的字符，count--；
                            count--;
                    }
                    left++;
                }
                
            }
        }
        return result;
    }
};