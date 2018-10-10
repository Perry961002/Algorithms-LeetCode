class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        if(len == 1)
            return {0};
        vector<int> res(len, 0);
        stack<int> s;//记录下标
        for(int i=0;i<len;i++){
            //找到栈顶元素的第一个递增元素下标
            while(!s.empty() && temperatures[i] > temperatures[s.top()]){
                int day = s.top();
                s.pop();
                res[day] = i - day;//求出等待天数
            }
            s.push(i);
        }
        return res;
    }
};