import java.util.*;

class Solution {
    public void dfs(int[] candidates, int target, int start, List<Integer> rec, List<List<Integer>> answer) {
        if (target < 0) // >target终止
            return;
        if (target == 0) // rec为一个解，放入解集
        {
            answer.add(rec); // 放入解集
            return;
        }
        for (int i = start; i < candidates.length; i++) {
            rec.add(candidates[i]); // 放入疑似解中
            dfs(candidates, target - candidates[i], i, rec, answer); // 深搜
            rec.remove(rec.size() - 1); // 回溯
        }
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<Integer> rec = new ArrayList<>();
        List<List<Integer>> answer = new ArrayList<>();
        this.dfs(candidates, target, 0, rec, answer);
        return answer;
    }
}