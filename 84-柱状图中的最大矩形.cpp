class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        /*
        //超出时间限制，用栈操作
        if(heights.size() == 0)
            return 0;
        //存放每一个height[i]的矩形面积
        vector<int> area(heights.size(),0);
        for(int i=0;i<heights.size();i++)
        {
            int curarea=heights[i];
            area[i]=heights[i];
            //向右边加
            for(int j=i+1;j<heights.size();j++)
            {
                if(heights[j]<curarea)
                    break;
                else
                    area[i]+=curarea;
            }
            //向左边加
            for(int k=i-1;k>=0;k--)
            {
                if(heights[k]<curarea)
                    break;
                else
                    area[i]+=curarea;
            }
        }
        //找出area[i]中最大的值
        int max=0;
        for(int i=0;i<area.size();i++)
        {
            if(area[i]>max)
                max=area[i];
        }
        return max;
        */
        if(heights.size() == 0) return 0;
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
};