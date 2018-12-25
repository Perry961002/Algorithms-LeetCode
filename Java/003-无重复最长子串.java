class Solution {
    int lengthOfLongestSubstring(String s) {
        int len = s.length();
        if (len < 2)
            return len;
        int[] map = new int[256]; // 存放出现的位置
        for (int i = 0; i < map.length; i++)
            map[i] = -1;
        int maxlen = 0, start = -1; // 最长不重复子串的长度，子串开始的下标
        for (int i = 0; i < len; i++) {
            if (map[s.charAt(i)] > start) // 出现重复字符
                start = map[s.charAt(i)]; // 被重复的字符上一次出现的下标
            map[s.charAt(i)] = i; // 不是重复的，记录他
            maxlen = Math.max(maxlen, i - start);
        }
        return maxlen;
    }
}