class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int second = INT_MIN;//保存每个三元组中间的数
        for(int i = nums.size()-1;i>=0;i--)
        {
            if(nums[i] < second)
                return true;
            else
            {
                while(!s.empty() && nums[i] > s.top())//比栈顶元素大
                {
                    second = s.top();
                    s.pop();
                }
            }
            s.push(nums[i]);
        }
        return false;
    }
};