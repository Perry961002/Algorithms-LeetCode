class Solution {
    public int[] searchRange(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        int[] result = new int[2];
        while (left <= right) {
            int mid = (left + right) / 2; // 二分查找
            if (nums[mid] == target) {
                int begin = mid, end = mid; // 找开始，结束位置
                while (begin >= left && nums[begin] == target)
                    begin--;
                while (end <= right && nums[end] == target)
                    end++;
                result[0] = begin + 1;
                result[1] = end - 1;
                return result;
            } else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        result[0] = -1; // 找不到目标值
        result[1] = -1;
        return result;
    }
}