class Solution {
public:
    int longestPalindrome(string s) {
        //回文串需要满足中心对称,如果一个字符出现偶数次,则他们肯定可以组成回文串
        //如果一个字符出现奇数次,先减一之后放入回文串中,所有字符统计完之后从剩下的字符中取一个放在中间即可
        if(s.size() == 0 || s.size() == 1)
            return s.size();
        int longest = 0;
        vector<int> ch(52, 0);
        bool flag = false;//是否出现奇数个字符
        for(auto c : s)
        {
            if(c >= 'a' && c <= 'z')
                ch[c - 'a'] ++;
            else
                ch[c - 'A' + 26] ++;
        }
        for(int i=0;i<52;i++)
        {
            if(ch[i] % 2 == 0)
                longest += ch[i];
            else
            {
                flag = true;
                longest += ch[i] - 1;
            }
        }
        if(flag)
            longest += 1;
        return longest;
    }
};