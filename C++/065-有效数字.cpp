class Solution {
public:
    bool isNumber(string s) {
        if(s == "")
            return false;
        int i = 0;
        while(s[i] != '\0' && s[i] == ' ')  //过滤前面的空格，后面只能在末尾出现
            i++;
        if(s[i] == '-' || s[i] == '+')  //正负号合法
            i++;
        bool fnum = false;  // e前面是不是数字
        bool fdot = false;  //.是否出现了
        bool fexp = false;  //e是否出现
        while(s[i] != '\0')
        {
            if(s[i] == '.' && !fdot)  //第一个.出现
            {
                fdot = true;
                i++;
            }
            else if(s[i] == 'e' && fnum && !fexp)  //e前面必须是数字，只出现一次
            {
                fexp = fdot = true; //后面不能再有e和.
                if(s[i + 1] != '\0' && (s[i + 1] == '+' || s[i + 1] == '-'))  //e后面一个字符可以是正负号
                    i++;
                if(s[i + 1] == '\0' || s[i + 1] < '0' || s[i + 1] > '9')  //e后面已经结束，或者不是数字。正负号后面已经结束，或者不是数字
                    return false;
                i++;
            }
            else if(s[i] >= '0' && s[i] <= '9')
            {
                fnum = true;  //出现的是数字
                i++;
            }
            else
                break;
        }
        while(s[i] != '\0' && s[i] == ' ')  //过滤后面的空格
                i++;
        return fnum && s[i] == '\0';  //是不是数字，或者数字后面都是空格
    }
};