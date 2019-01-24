class Solution {
    public void sortColors(int[] nums) {
        // start表示0结束的下标,end表示2开始的下标
        int start = 0, end = nums.length - 1;
        // 注意结束条件,是end
        for (int i = 0; i <= end; ++i) {
            // 把0放前面
            if (nums[i] == 0) {
                int tmp = nums[i];
                nums[i] = nums[start];
                nums[start] = tmp;
                ++start;
            }
            // 把2放后面
            else if (nums[i] == 2) {
                int tmp = nums[i];
                nums[i] = nums[end];
                nums[end] = tmp;
                --end;
                --i;// 需要检查交换过去的数
            }
        }
    }
}