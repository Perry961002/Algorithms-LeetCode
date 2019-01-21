import java.util.Stack;

class Solution {
    public String simplifyPath(String path) {
        if (path.length() == 0)
            return "";
        int len = path.length();
        Stack<String> rec = new Stack<>(); // 记录路径中一个节点的栈
        int i = 0;
        while (i < len) {
            // while (i < path.length() && path.charAt(i) == '/') // 遇到/,跳过
            // i++;
            String temp = ""; // 记录节点
            while (i < len && path.charAt(i) != '/') {
                temp += path.charAt(i);
                i++;
            }
            // 下面判断节点是不是特殊字符
            if (temp == ".." && rec.isEmpty()) // ".." 返回根节点
                rec.pop();
            else if (temp != "" && temp != ".." && temp != ".") // 节点符合要求
                rec.push(temp);
        }
        if (rec.isEmpty()) // 说明是根节点
            return "/";
        String result = "";
        while (!rec.isEmpty()) {
            result = "/" + rec.lastElement() + result; // 栈是先进后出，所以路径要从右向左构造
            rec.pop();
        }
        return result;
    }
}