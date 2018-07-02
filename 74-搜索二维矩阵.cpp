class Solution {
public:
    /*
    *将二维矩阵当成一维数组搜索
    */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        int m = matrix.size();int n = matrix[0].size();int len = n*m;
        for(int i=0;i<len;i++)
        {
            if(matrix[i/n][i%n]==target)
                return true;
            if(matrix[i/n][i%n]>target)
                break;
        }
        return false;
    }
};