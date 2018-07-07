class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        //将二维矩阵当成一维数组搜索
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
        /*
        //二分搜索
        if (matrix.empty() || matrix[0].empty()) return false;
        if (target < matrix[0][0] || target > matrix.back().back()) return false;
        int left = 0, right = matrix.size() - 1;
        while (left <= right)   //二分搜索第一列
        {
            int mid = (left + right) / 2;
            if (matrix[mid][0] == target)
                return true;
            else if (matrix[mid][0] < target) 
                left = mid + 1;
            else 
                right = mid - 1;
        }
        int tmp = right;
        left = 0;
        right = matrix[tmp].size() - 1;
        while (left <= right)   //二分搜索行
        {
            int mid = (left + right) / 2;
            if (matrix[tmp][mid] == target) 
                return true;
            else if (matrix[tmp][mid] < target) 
                left = mid + 1;
            else 
                right = mid - 1;
        }
        return false;
        */
    }
};