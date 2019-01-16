class Solution {
    public int uniquePaths(int m, int n) {
        if (m > n) {
            int tmp = m;
            m = n;
            n = tmp;
        } // 选小的数
        long result = 1; // 初始化
        for (int i = 1; i <= m - 1; i++) {
            result = (long) (m + n - 1 - i) * result / i;
        }
        return (int) result;
    }
}