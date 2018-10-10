class Solution {
public:
    /**
    *首先判断p是否为空，为空的话返回s是否为空
    *p多于两个字符并且第二个字符为*,因为*前面可以有0个字符，递归可为0的情况，即去掉p的前两个字符
        *或者s不为空，并且p和s的第一个字符相同，去掉p的前一个字符递归
    *p的第二个字符不是*，则比较p和s的第一个字符，并且递归
    */
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        if( p.size()>1 && p[1] =='*')
            return isMatch(s,p.substr(2)) || ( !s.empty() && ( s[0]==p[0] || p[0]=='.') && isMatch(s.substr(1),p) );
        else
        {
            return !s.empty() && ( ( s[0]==p[0] || p[0]=='.') && isMatch(s.substr(1),p.substr(1)) );
        }
    }
};