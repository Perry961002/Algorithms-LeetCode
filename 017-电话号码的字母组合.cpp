class Solution {
public:
    void create(string& digits, vector<string>& result, string& rec, map<char,string>& transform)
    {
        int len = rec.size();  //字母组合的长度
        if(len == digits.size())   //将一个组合放入解集
            result.push_back(rec);
        else
        {
            for(int i=0;i<transform[ digits[len] ].size();i++)
            {
                rec += transform[ digits[len] ][i];
                create(digits, result, rec, transform);
                rec.pop_back();  //回溯
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> result;  //结果集
        string rec="";    //单个字母组合
        if(digits.size() == 0)
            return result;
        map<char,string> transform;   //建数组和字母的hash表
        transform['2'] = "abc";
        transform['3'] = "def";
        transform['4'] = "ghi";
        transform['5'] = "jkl";
        transform['6'] = "mno";
        transform['7'] = "pqrs";
        transform['8'] = "tuv";
        transform['9'] = "wxyz";
        create(digits, result, rec, transform);
        return result;
    }
};