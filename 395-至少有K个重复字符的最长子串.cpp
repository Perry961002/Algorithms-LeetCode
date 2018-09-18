class Solution {
public:
    int longest(string s, int k, int start, int end)
    {
        if(start > end)
            return 0;
        vector<int> snum(26, 0);
        //统计频率
        for(int i=start;i<=end;i++)
            snum[s[i] - 'a'] ++;
        for(int i=0;i<26;i++)
        {
            //找到频率不符合要求的字符第一次出现的位置,然后分治
            if(snum[i] > 0 && snum[i] < k)
            {
                int index = s.find( (char)(i + 'a'), start);
                return max(longest(s,k,start,index-1), longest(s,k,index+1,end));
            }
        }
        return end-start+1;
    }
    int longestSubstring(string s, int k) {
        return longest(s,k,0,s.size()-1);
    }
};