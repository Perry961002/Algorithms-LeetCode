class Solution {
    public int lengthOfLastWord(String s) {
        if (s.isEmpty())
            return 0;
        boolean flag = false;// 是最后一个单词的标志
        int len = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) == ' ' && flag == false)
                continue;
            if (s.charAt(i) != ' ') {
                len++;
                flag = true;
            } else
                break;
        }
        return len;
    }
}