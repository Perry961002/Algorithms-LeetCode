static const auto ban_io_sync = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    string simplifyPath(string path) {
        if(path.size() == 0) return "";
        int len = path.size();
        stack<string> rec;  //记录路径中一个节点的栈
        int i = 0;
        while(i < len)
        {
            while(path[i] == '/')  //遇到/,跳过
                i++;
            string temp = "";   //记录节点
            while(i < len && path[i] != '/')
            {
                temp += path[i];
                i++;
            }
            //下面判断节点是不是特殊字符
            if(temp == ".." && rec.empty()==0)   //".." 返回根节点
                rec.pop();
            else if(temp != "" && temp != ".." && temp != ".")   //节点符合要求
                rec.push(temp);
        }
        if(rec.empty())  //说明是根节点
            return "/";
        string result = "";
        while(!rec.empty())
        {
            result = "/" + rec.top() + result;   //栈是先进后出，所以路径要从右向左构造
            rec.pop();
        }
        return result;

    }
};