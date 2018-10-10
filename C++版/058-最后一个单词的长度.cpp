class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty())
            return 0;
        bool flag = false;//是最后一个单词的标志
        int len = 0;
        for(int i=s.size() - 1;i>=0;i--)
        {
            if(s[i] == ' ' && flag == false)
                continue;
            if(s[i] != ' ')
            {
                len ++;
                flag = true;
            }
            else
                break;
        }
        return len;
    }
};