class Solution {
public:
    /*
    *自底向上搜索，遇到比target大的，就从上一行相同的位置开始
    *找的话停止
    */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        int m = matrix.size()-1;
        int n = matrix[0].size()-1;
        int x = m;int y = 0;
        while(x>=0&&y<=n)
        {
            if(matrix[x][y]==target)
                return true;
            else if(matrix[x][y]>target)
                --x;
            else
                ++y;
        }
        return false;
    }
};