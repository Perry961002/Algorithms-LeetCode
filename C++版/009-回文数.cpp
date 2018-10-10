static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int position = 1;//记录位权
        while(x / 10 / position)
            position *= 10;
        while(x)
        {
            //比较最高位和最低位
            if(x / position != x %10)
                return false;
            else
            {
                x = x % position / 10;//去除最高位和最低位
                position /= 100;
            }
        }
        return true;
    }
};