class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0)
            return "";
        if (strs.length == 1)
            return strs[0];
        String str = "";
        for (int i = 0; i < strs[0].length(); i++) {
            for (int j = 1; j < strs.length; j++) {
                if (i >= strs[j].length())
                    return str;
                if (strs[0].charAt(i) != strs[j].charAt(i))
                    return str;
            }
            str += strs[0].charAt(i);
        }
        return str;
    }
}