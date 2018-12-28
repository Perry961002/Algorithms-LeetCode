import java.util.*;

class Solution {
    public List<List<Integer>> answer;

    public void dfs(int[] candidates, int target, int start, Stack<Integer> rec) {
        if (target < 0) {// >target终止
            return;
        }
        if (target == 0) // rec为一个解，放入解集
        {
            this.answer.add(new ArrayList<>(rec)); // 放入解集
            return;
        }
        for (int i = start; i < candidates.length; i++) {
            rec.push(candidates[i]); // 放入疑似解中
            dfs(candidates, target - candidates[i], i, rec); // 深搜
            rec.pop(); // 回溯
        }
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Stack<Integer> rec = new Stack<Integer>();
        this.answer = new ArrayList<>();
        this.dfs(candidates, target, 0, rec);
        return answer;
    }
}