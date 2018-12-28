import java.util.*;

class Solution {
    public List<List<Integer>> answer;

    void dfs(int[] candidates, int target, int start, Stack<Integer> rec) {
        if (target < 0) // >target终止
            return;
        else if (target == 0) // rec为一个解，放入解集
        {
            answer.add(new ArrayList<>(rec)); // 放入解集
            return;
        } else
            for (int i = start; i < candidates.length; i++) {
                if (i > start && candidates[i] == candidates[i - 1])
                    continue; // 从重复数字的下一个开始
                rec.push(candidates[i]); // 放入疑似解中
                dfs(candidates, target - candidates[i], i + 1, rec); // 深搜
                rec.pop(); // 回溯

            }
    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        answer = new ArrayList<>();
        dfs(candidates, target, 0, new Stack<Integer>());
        return answer;
    }
}