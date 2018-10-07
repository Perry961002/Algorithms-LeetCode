class Solution {
public:
    bool checkValidString(string s) {
        //记录左括号,*号的位置
        stack<int> left, start;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(')
                left.push(i);
            else if(s[i] == '*')
                start.push(i);
            else{
                //遇到')'
                //还有左括号
                if(!left.empty())
                    left.pop();
                //把*当左括号
                else if(!start.empty())
                    start.pop();
                else
                    return false;//右括号肯定多了
            }
        }
        while(!left.empty() && !start.empty()){
            //*在左括号之前
            if(start.top() < left.top())
                return false;
            else{
                //把*当右括号
                left.pop();
                start.pop();
            }
        }
        return left.empty();
    }
};