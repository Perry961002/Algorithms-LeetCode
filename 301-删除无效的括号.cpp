class Solution {
public:
    /*
    *遍历字符串，当")"的个数比"("多的时候删除前面任意一个多余的")",并继续下去
    *考虑到删除")"可能会出现相同的结果，所以记录最后一个删除的位置，接下来接下来删除的时候只删除这个位置之后的值
    *上面的方法只能去除非法的")",对于非法的"(",只需换个方向后按上面的方法去除"("
    */
    
    //ch表示需要检查合法的括号，last记录最后删除的位置
    void dfs(string s, char ch, int last)
    {
        int len = s.size();
        //遍历字符串。cnum表示ch出现的个数
        for(int i=0,cnum = 0;i<len;i++)
        {
            if(s[i] == '(' || s[i] == ')')
                (s[i] == ch) ? cnum ++ : cnum --;
            //没有出现非法的括号
            if(cnum <= 0)
                continue;
            //删除前面的任意一个非法括号
            for(int j=last;j<=i;j++)
            {
                if(s[j] == ch && (j ==last || s[j-1] != ch))
                    dfs(s.substr(0, j)+s.substr(j+1), ch, j);
            }
            return;
        }
        reverse(s.begin(), s.end());
        if(ch == ')')
            return dfs(s, '(', 0);
        result.push_back(s);
    }
    vector<string> removeInvalidParentheses(string s) {
        dfs(s, ')', 0);
        return result;

    }
private:
    vector<string> result;
};