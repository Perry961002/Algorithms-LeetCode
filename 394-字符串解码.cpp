class Solution {
public:
    string decodeString(string s) {
        string res = "";
        stack<int> num;//存数字
        stack<string> str;//存字符串
        int i = 0;
        while(i < s.size())
        {
            //遇到数字
            if(s[i] >= '0' && s[i] <= '9')
            {
                int count = 0;
                while(s[i] >= '0' && s[i] <= '9')
                {
                    count = count * 10 + (s[i] - '0');
                    i++;
                }
                num.push(count);
            }
            else if(s[i] == '[')
            {
                str.push(res);//之前的字符入栈
                res = "";//重置
                i++;
            }
            else if(s[i] == ']')
            {
                string pre = str.top();
                str.pop();
                int count = num.top();
                num.pop();
                //pre是之前的结果, res是现在需要重复的,应该把res接在pre后面
                while(count--)
                    pre += res;
                res = pre;//更新
                i++;
            }
            else
            {
                res += s[i];//遇到字母
                i++;
            }
        }
        return res;
    }
};
