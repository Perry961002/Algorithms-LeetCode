import java.util.*;

class Solution {
    public String[] num = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    List<String> result;

    public void create(int[] input, int index, String tmp) {
        if (index >= input.length) {
            result.add(tmp);
        } else {
            for (int i = 0; i < num[input[index]].length(); i++) {
                create(input, index + 1, tmp + num[input[index]].charAt(i));
            }
        }
    }

    public List<String> letterCombinations(String digits) {
        this.result = new ArrayList<>();
        int[] input = new int[digits.length()];
        if (digits.length() == 0)
            return result;
        for (int i = 0; i < digits.length(); i++) {
            input[i] = digits.charAt(i) - '0' - 2;
        }
        create(input, 0, "");
        return result;
    }
}