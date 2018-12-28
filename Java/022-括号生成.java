import java.util.*;

class Solution {
    public List<String> result;

    public void create(String rec, int left, int right) {
        if (left < 0 || right < 0)
            return;
        else if (left == 0 && right == 0) {
            int count = 0;
            for (int i = 0; i < rec.length(); i++) {
                if (rec.charAt(i) == '(')
                    count++;
                else
                    count--;
                if (count < 0)
                    return;
            }
            result.add(rec);
        } else {
            create(rec + "(", left - 1, right);
            create(rec + ")", left, right - 1);
        }
    }

    public List<String> generateParenthesis(int n) {
        result = new ArrayList<>();
        if (n == 0)
            return result;
        create("(", n - 1, n);
        return result;
    }
}