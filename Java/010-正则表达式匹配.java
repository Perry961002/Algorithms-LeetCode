class Solution {
    /**
     * 首先判断p是否为空，为空的话返回s是否为空 p多于两个字符并
     * 第二个字符为*,因为*前面可以有0个字符，递归可为0的情况，即去掉p的前两个字符
     * 或者s不为空，并且p和s的第一个字符相同，去掉p的前一个字符递归 p的第二个字符不是*，则比较
     * 和s的第一个字符，并且递归
     */
    public boolean isMatch(String s, String p) {
        if (p.isEmpty())
            return s.isEmpty();
        if (p.length() > 1 && p.charAt(1) == '*')
            return isMatch(s, p.substring(2)) || (!s.isEmpty() && (s.charAt(0) == p.charAt(0) || p.charAt(0) == '.')
                    && isMatch(s.substring(1), p));
        else {
            return !s.isEmpty()
                    && ((s.charAt(0) == p.charAt(0) || p.charAt(0) == '.') && isMatch(s.substring(1), p.substring(1)));
        }
    }
}