class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        // 将二维矩阵当成一维数组搜索
        if (matrix.length == 0)
            return false;
        int m = matrix.length;
        int n = matrix[0].length;
        int len = n * m;
        for (int i = 0; i < len; i++) {
            if (matrix[i / n][i % n] == target)
                return true;
            if (matrix[i / n][i % n] > target)
                break;
        }
        return false;
    }
}