class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*
        //法1.二分搜索  99.3%击败率  O(n * log n)复杂度
        int start = 1, end = nums.size() - 1;
        int mid = 0;
        while(start < end)
        {
            mid = (start + end) / 2;
            int count = 0;  //计算mid出现的次数
            for(auto i : nums)
                if(i <= mid)
                    count++;
            if(count > mid)
                end = mid;
            else
                start = mid + 1;
        }
        return start;
        */
        //法2.快慢指针法  O(n)复杂度，99.3%击败率
        int slow = nums[0];
        int fast = nums[nums[0]];
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};