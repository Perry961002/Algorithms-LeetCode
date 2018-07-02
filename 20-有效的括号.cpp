class Solution {
public:
    bool isValid(string s) {
        stack<char> rec;  //实现栈
        for(int i=0;i<s.length();i++)  //遍历s的每一个字符
        {
            if( !rec.empty() && s[i]==')' && rec.top()=='(')  //栈不空，当前字符是')',栈顶为'('
                rec.pop();   //弹出'('
            else if( !rec.empty() && s[i]==']' && rec.top()=='[')  //栈不空，当前字符是']',栈顶为'['
                rec.pop();   //弹出'['
            else if( !rec.empty() && s[i]=='}' && rec.top()=='{')  //栈不空，当前字符是'}',栈顶为'{'
                rec.pop();   //弹出'{'
            else
                rec.push(s[i]);
        }
        return rec.empty();   //栈空说明有效
    }
};