class Solution {
public:
    void create(int left,int right,string rec,vector<string>& answer)  //left表示左括号剩下的个数，right表示右括号剩下的个数
    {
        if(left > right) return;   //右括号使用的多，字符串已经非法，结束
        if(left == 0 && right == 0)   //括号生成完，返回解
            answer.push_back(rec);
        else
        {
            if(left>0)
                create(left-1,right,rec+'(',answer);   //放左括号，递归
            if(right>0)
                create(left,right-1,rec+')',answer);   //放右括号，递归
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        string rec="";
        create(n,n,rec,answer);
        return answer;
    }
};