import java.util.*;

class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> result = new ArrayList<>();
        if (s == "" || words.length == 0)
            return result;
        int slen = s.length(); // s的长度
        int wordlen = words[0].length(); // 单个词的长度
        int wordcount = words.length; // 单词的个数
        int findlen = wordlen * wordcount; // 每次应该在s中需要匹配的字符的长度
        // 建立hash表
        HashMap<String, Integer> book = new HashMap<>();
        for (String word : words) {
            if (book.get(word) == null)
                book.put(word, 1);
            else
                book.put(word, book.get(word) + 1);
        }
        int i = 0;
        int a = 0;
        int count; // 记录匹配到的字符的个数
        while (i <= slen - findlen) {
            count = 0;
            HashMap<String, Integer> temp = new HashMap<>(book); // 复制一份hash表
            int k = i;
            while (k <= i + findlen) {
                String tempword = s.substring(k, k + wordlen); // 取出一个单位长度的单词
                if (temp.get(tempword) == null) {
                    // 没有找到单词，说明以i为起点一定找不到一个完全的匹配,从i的下一个位置开始
                    i++;
                    break;
                } else // 匹配了一个单词
                {
                    int t = temp.get(tempword);
                    if (t > 0) // 防止在findlen的长度里出现了过度匹配的情况
                    {
                        temp.put(tempword, t - 1);
                        count++;
                        k += wordlen; // 从下一个单词开始
                    } else // 出现了过度的匹配
                    {
                        i++;
                        break;
                    }
                }
                if (count == wordcount) // words中的单词都匹配了
                {
                    result.add(i);
                    i++;
                    break;
                }
            }
        }
        return result;
    }
}
