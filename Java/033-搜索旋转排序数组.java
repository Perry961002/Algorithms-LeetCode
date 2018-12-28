class Solution {
    public int search(int[] nums, int target) {
        int start = 0;
        int end = nums.length - 1;
        int mid = 0;
        while (start <= end) {
            mid = (start + end) / 2;
            if (target == nums[mid]) // 找到了
                return mid;
            else if (target > nums[mid]) {
                if (nums[start] > nums[end] && nums[mid] < nums[end] && target > nums[end]) // target在前半部分，mid在后半
                    end = mid - 1;
                else
                    start = mid + 1;
            } else {
                if (nums[start] > nums[end] && nums[mid] >= nums[start] && target < nums[start]) // mid在前半部分,target在后半部分
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return -1;
    }
}