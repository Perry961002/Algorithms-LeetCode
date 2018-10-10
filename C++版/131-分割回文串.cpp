class Solution {
public:
    bool isP(string& s,int start,int end)  //判断是不是回文数
    {
        while(start < end)
        {
            if(s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    void dfs(string& s, vector<string>& rec,vector<vector<string>>& result,int index)
    {
        if(index == s.size())   //遍历完
        {
            result.push_back(rec);
            return;
        }
        for(int i = index;i<s.size();i++)
        {
            if( isP(s,index,i) ) //判断从index 到 i位置的是不是回文串
            {
                rec.push_back( s.substr(index,i - index + 1) );
                dfs(s,rec,result,i + 1);
                rec.pop_back();  //回溯
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> rec;
        vector<vector<string>> result;
        dfs(s,rec,result,0);
        return result;
    }
};