class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        if (nums == null || nums.length == 0)
            return result;
        // 这里就需要排序了，给以后跳过重复数字埋下伏笔
        Arrays.sort(nums);
        // 剩下都是一样的
        List<Integer> list = new ArrayList<>();
        dfs(result, list, 0, nums);
        return result;
    }

    public void dfs(List<List<Integer>> result, List<Integer> list, int start, int[] nums) {
        result.add(new ArrayList<>(list));
        for (int i = start; i < nums.length; i++) {
            // 关键就在这一句，每次循环起始的数字不能和之前重复。
            if (i > start && nums[i] == nums[i - 1])
                continue;
            list.add(nums[i]);
            dfs(result, list, i + 1, nums);
            list.remove(list.size() - 1);
        }
    }
}