class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0 , right = nums.size() - 1;
        vector<int> result;
        while(left <= right)
        {
            int mid = (left + right)/2;  //二分查找
            if(nums[mid] == target)
            {
                int begin = mid , end = mid;   //找开始，结束位置
                while(begin >=left && nums[begin] == target)
                    begin--;
                while(end <= right && nums[end] == target)
                    end++;
                result.push_back(begin + 1);
                result.push_back(end - 1);
                return result;
            }
            else if( nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        result.push_back(-1);   //找不到目标值
        result.push_back(-1);
        return result;
    }
};