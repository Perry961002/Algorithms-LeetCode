static const auto ban_io_sync = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int maxArea(vector<int>& heights)
    {
        stack<int> rect;  //实现栈
        int result = 0;   //记录的面积
        for(int i=0;i<heights.size();i++)
        {
            if( rect.empty() || heights[i]>=rect.top() )  //栈空，或者满足升序条件
                rect.push(heights[i]);
            else
            {
                int count = 0;  //记录栈中比heights[i]小的个数
                while( !rect.empty() && rect.top()>heights[i] )  //将栈中比heights[i]小的都弹出
                {
                    count++;  //个数加1
                    result = max(result,rect.top()*count);   //更新
                    rect.pop();
                }
                while( count>0 )   //将之前弹出的都改为heights[i]
                {
                    rect.push(heights[i]);
                    count--;
                }
                rect.push(heights[i]);  //入栈当前的矩形
            }
        }
        int count = 1;
        while( !rect.empty() )   //计算当前栈中形成的面积
        {
            result = max(result,rect.top()*count);   //更新
            rect.pop();  //出栈
            count++;
        }
        return result;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        int m = matrix.size() , n = matrix[0].size();
        vector<int> dp(n);  //dp[i]表示当前行每列位置上矩形的高度
        int maxarea = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i == 0)
                    dp[j] = matrix[i][j] - '0';  //第一行上矩形的高度
                else
                {
                    if(matrix[i][j] == '0')
                        dp[j] = 0;
                    else
                        dp[j] += 1;  //如果当前是1，说明与上一行可以形成矩形
                }
            }
            maxarea = max(maxarea,maxArea(dp));   //逐行求最大值
        }
        return maxarea;
    }
};