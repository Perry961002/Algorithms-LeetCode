import java.util.*;

class Solution {
    public boolean isValid(String s) {
        Stack<Character> rec = new Stack<Character>(); // 实现栈
        for (int i = 0; i < s.length(); i++) // 遍历s的每一个字符
        {
            if (!rec.empty() && s.charAt(i) == ')' && rec.lastElement() == '(') // 栈不空，当前字符是')',栈顶为'('
                rec.pop(); // 弹出'('
            else if (!rec.empty() && s.charAt(i) == ']' && rec.lastElement() == '[') // 栈不空，当前字符是']',栈顶为'['
                rec.pop(); // 弹出'['
            else if (!rec.empty() && s.charAt(i) == '}' && rec.lastElement() == '{') // 栈不空，当前字符是'}',栈顶为'{'
                rec.pop(); // 弹出'{'
            else
                rec.push(s.charAt(i));
        }
        return rec.empty(); // 栈空说明有效
    }
}