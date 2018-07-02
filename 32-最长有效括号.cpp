class Solution {
public:
    /*
    *用栈记录括号的位置
    *当发现有成对括号时，弹出左括号的位置，如果此时栈空，则max=i+1
    *如果不空，并且此时成对括号的长度超过max，则更新max
    */
    int longestValidParentheses(string s) {
        stack<int> rec; // 记录成对括号的位置
        int max=0;  //最大长度
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==')'&&!rec.empty()&&s[rec.top()]=='(')
            {
                rec.pop();
                if(rec.empty())
                    max = i+1;
                else
                {
                    if(i-rec.top()>max)
                        max = i-rec.top();
                }
            }
            else
                rec.push(i);
        }
        return max;
    }
};