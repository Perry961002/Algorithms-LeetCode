class Solution {
    public boolean isMatch(String s, String p) {
        int index_s = 0; // s的下标
        int index_p = 0; // p的下标
        int p_start = -1; // p中*出现的位置
        int s_start = 0; // s中*匹配的位置
        while (index_s < s.length()) {
            if (index_p < p.length() && (s.charAt(index_s) == p.charAt(index_p) || p.charAt(index_p) == '?'))// s和p对应位置的字符相等，或者p的字符？
            {
                index_s++; // 匹配s下一个
                index_p++; // 匹配p下一个
            } else if (index_p < p.length() && p.charAt(index_p) == '*') // p的字符是*
            {
                p_start = index_p; // 保存p中出现*的位置
                index_p++; // 更新到下一个字符,s的位置不变，让*一开始匹配空
                s_start = index_s; // 保存s已经匹配的位置
            } else if (p_start != -1) // 以上情况都不满足，但p中已经出现*
            {
                index_p = p_start + 1; // 回到上一次的后一个字符
                s_start++; // s上一次匹配*的位置+1，即让*多匹配一个字符
                index_s = s_start;
            } else
                return false; // 都不满足，说明已经出现错误
        }
        while (index_p < p.length() && p.charAt(index_p) == '*') // s已经匹配完，处理p剩下字符中的*
            index_p++;
        return index_p == p.length(); // p剩下字符的*已经处理完，如果p空说明匹配成功，否则失败
    }
}
