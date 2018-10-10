class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26, 0);//统计s中各字母出现的次数
        vector<bool> visited(26,false);//记录在字典序最小串中出现的字母
        string res = "0";
        for(char c : s)
            count[c-'a'] ++;
        for(char c : s)
        {
            count[c-'a'] --;
            if(visited[c-'a'])
                continue;
            //后面的条件使得只出现一次的字母会被保留
            while(c < res.back() && count[res.back() -'a'])
            {
                visited[res.back() -'a'] = false;
                res.pop_back();
            }
            visited[c-'a'] = true;
            res += c;
        }
        return res.substr(1);
    }
};