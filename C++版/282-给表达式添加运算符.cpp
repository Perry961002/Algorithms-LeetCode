class Solution {
public:
    /*采用深搜法
    *res:结果集合
    *num:需要被插入运算符的字符串
    *target:目标数
    *tmp:暂时的一个可能情况
    *currRes:暂时算出的结果
    *prevNum:上次保存的左操作数
    */
    void dfs(vector<string>& res, string num, int target, string tmp, long currRes, long prevNum){
        //一个正确的插入方式找到
        if(num.size() == 0 && currRes == target){
            res.push_back(tmp);
            return;
        }
        for(int i=1;i<=num.size();i++){
            string currStr = num.substr(0, i);
            //排除前导为0的情况
            if(currStr.size() > 1 && currStr[0] == '0')
                return;
            long currNum = stol(currStr);
            //取得下一个需要深搜的字符串
            string nextStr = num.substr(i);
            //不是第一次的深搜
            if(tmp.size() > 0){
                // '*'情况
                dfs(res, nextStr, target, tmp + '*' + currStr, currRes - prevNum + prevNum * currNum, prevNum * currNum);
                // '+'情况
                dfs(res, nextStr, target, tmp + '+' + currStr, currRes + currNum, currNum);
                // '-'情况
                dfs(res, nextStr, target, tmp + '-' + currStr, currRes - currNum, -currNum);
            }
            else
                dfs(res, nextStr, target, currStr, currNum, currNum);
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        dfs(res, num, target, "",0, 0);
        return res;
    }
};