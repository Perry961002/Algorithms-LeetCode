static const auto ban_io_sync = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int myAtoi(string str) {
        if(str == "")
            return 0;
        long long result = 0; //因为要比较是不是溢出，所以用长整型
        int flag = 1;  //判断是不是负数
        int i = 0;
        while(str[i] != '\0' && str[i] == ' ')  //去掉空格
            i++;
        if(str[i] == '-')  //遇到符号
        {
            flag = -1;
            i++;
        }
        else if(str[i] == '+')  //遇到正号
            i++;
        while(str[i] != '\0')
        {
            if(str[i] >= '0' && str[i] <= '9')  //正负号之后是有效数字
            {
                result = result * 10 + (str[i] - '0');
                if(result > INT_MAX)  //溢出
                {
                    if(flag == -1)
                        return INT_MIN;
                    else
                        return INT_MAX;
                }
                i++;
            }
            else  //遇到不是数字
                break;
        }
        return (int)(result * flag);
    }
};