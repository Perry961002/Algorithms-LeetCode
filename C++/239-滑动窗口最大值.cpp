class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> deq;  //存放窗口元素的下标,保证队头元素总是最大值
        vector<int> result;
        int len = nums.size();
        for(int i = 0;i<len;i++)
        {
            while(!deq.empty() && i - deq.front() >= k) //窗口元素的数量将超过k,队头元素出队
                deq.pop_front();
            while(!deq.empty() && nums[i] >= nums[deq.back()])  //队头元素比nums[i]大就删除
                deq.pop_back();
            deq.push_back(i);
            if(i >= k - 1)
                result.push_back(nums[deq.front()]);
        }
        return result;
    }
};