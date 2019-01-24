class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        List<Integer> tmp = new ArrayList<Integer>();
        dfs(res, tmp, n, k, 1);
        return res;
    }

    public void dfs(List<List<Integer>> res, List<Integer> tmp, int n, int k, int m) {
        if (k == 0) {
            res.add(new ArrayList<Integer>(tmp));
            return;
        }
        for (int i = m; i <= n; i++) {
            tmp.add(i);
            dfs(res, tmp, n, k - 1, i + 1);
            tmp.remove(tmp.size() - 1);
        }
    }
}
