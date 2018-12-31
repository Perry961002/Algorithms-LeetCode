import java.util.*;

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> result = new ArrayList<>(); // 结果
        HashMap<String, List<String>> rec = new HashMap<>(); // 排序后的词作为键
        for (int i = 0; i < strs.length; i++) {
            String str = strs[i];
            byte[] a = str.getBytes();
            Arrays.sort(a); // 对单词按字典序排序
            str = new String(a);
            List<String> t = rec.get(str);
            if (t == null)
                t = new ArrayList<>();
            t.add(strs[i]);
            rec.put(str, t);
        }
        Iterator iter = rec.entrySet().iterator();
        while (iter.hasNext()) // auto是智能指针
        {
            Map.Entry<String, List<String>> entry = (Map.Entry) iter.next();
            result.add(entry.getValue());
        }
        return result;
    }
}