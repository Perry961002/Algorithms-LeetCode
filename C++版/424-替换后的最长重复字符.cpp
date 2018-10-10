class Solution {
public:
    int characterReplacement(string s, int k) {
        //采用滑动窗口法
        int start = 0, end = 0, mostchar = 0;//窗口的起始下标,结束下标,窗口中出现最多的字符次数
        int longest = 0;
        vector<int> count(26, 0);
        while(end < s.size())
        {
            mostchar = max(mostchar, ++ count[s[end] - 'A']);
            //需要替换的字符超出限制
            while(end - start + 1 - mostchar > k)
                count[s[start ++] - 'A']--;
            longest = max(longest, end - start + 1);
            end++;
        }
        return longest;
    }
};