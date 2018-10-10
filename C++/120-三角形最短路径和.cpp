class Solution {
public:
    /*
    *贪心算法：
    *从倒数第二层开始遍历，选取下一层中与他相邻两个数中最小的一个
    *最后输出第一个元素
    */
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty()) return 0;
        for(int i=triangle.size()-2;i>=0;i--)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                triangle[i][j] += min(triangle[i+1][j],triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};