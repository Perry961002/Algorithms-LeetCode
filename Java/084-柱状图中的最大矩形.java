import java.util.Stack;

class Solution {
    public int largestRectangleArea(int[] heights) {
        if (heights.length == 0)
            return 0;
        Stack<Integer> rect = new Stack<>(); // 实现栈
        int result = 0; // 记录的面积
        for (int i = 0; i < heights.length; i++) {
            if (rect.empty() || heights[i] >= rect.lastElement()) // 栈空，或者满足升序条件
                rect.push(heights[i]);
            else {
                int count = 0; // 记录栈中比heights[i]小的个数
                while (!rect.empty() && rect.lastElement() > heights[i]) // 将栈中比heights[i]小的都弹出
                {
                    count++; // 个数加1
                    result = Math.max(result, rect.lastElement() * count); // 更新
                    rect.pop();
                }
                while (count > 0) // 将之前弹出的都改为heights[i]
                {
                    rect.push(heights[i]);
                    count--;
                }
                rect.push(heights[i]); // 入栈当前的矩形
            }
        }
        int count = 1;
        while (!rect.empty()) // 计算当前栈中形成的面积
        {
            result = Math.max(result, rect.lastElement() * count); // 更新
            rect.pop(); // 出栈
            count++;
        }
        return result;

    }
}