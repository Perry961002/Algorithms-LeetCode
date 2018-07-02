class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> rec;   //实现栈
        int len = tokens.size();  //长度
        if(len == 0) return 0;
        int i;
        for(i=0;i<len;i++)
        {
            // +法实现
            if(tokens[i] == "+")
            {
                int a = rec.top();
                rec.pop();
                int b = rec.top();
                rec.pop();
                rec.push(a+b);
            }
            // -法实现
            else if(tokens[i] == "-")
            {
                int a = rec.top();
                rec.pop();
                int b = rec.top();
                rec.pop();
                rec.push(b-a);
            }
            // *法实现
            else if(tokens[i] == "*")
            {
                int a = rec.top();
                rec.pop();
                int b = rec.top();
                rec.pop();
                rec.push(a*b);
            }
            // +法实现
            else if(tokens[i] == "/")
            {
                int a = rec.top();
                rec.pop();
                int b = rec.top();
                rec.pop();
                rec.push(b/a);
            }
            else
            {
                int a = stoi(tokens[i]);
                rec.push(a);
            }
        }
        return rec.top();
    }
};