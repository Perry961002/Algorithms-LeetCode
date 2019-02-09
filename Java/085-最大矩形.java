class Solution {
    private int maxRectangle(char[][] matrix, int row, int col) {
        int minWidth = Integer.MAX_VALUE;
        int maxArea = 0;
        for (int i = row; i < matrix.length && matrix[i][col] == '1'; i++) {
            int width = 0;
            while (col + width < matrix[row].length && matrix[i][col + width] == '1') {
                width++;
            }
            if (width < minWidth) {
                minWidth = width;
            }
            int area = minWidth * (i - row + 1);
            if (area > maxArea)
                maxArea = area;
        }
        return maxArea;
    }

    public int maximalRectangle(char[][] matrix) {
        int m = matrix.length;
        int n = m == 0 ? 0 : matrix[0].length;
        int maxArea = 0;
        for (int i = 0; i < m; i++) {// row
            for (int j = 0; j < n; j++) {// col
                if (matrix[i][j] == '1') {
                    int area = maxRectangle(matrix, i, j);
                    if (area > maxArea)
                        maxArea = area;
                }
            }
        }
        return maxArea;
    }
}
