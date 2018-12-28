import java.util.*;

class Solution {
    public int longestValidParentheses(String s) {
        Stack<Integer> rec = new Stack<>();// 记录成对括号的位置
        int max = 0; // 最大长度
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ')' && !rec.empty() && s.charAt(rec.lastElement()) == '(') {
                rec.pop();
                if (rec.empty())
                    max = i + 1;
                else {
                    if (i - rec.lastElement() > max)
                        max = i - rec.lastElement();
                }
            } else
                rec.push(i);
        }
        return max;
    }
}