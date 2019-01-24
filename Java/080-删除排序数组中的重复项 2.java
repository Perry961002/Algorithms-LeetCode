class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums.length < 3) // 长度小于3，直接输出
            return nums.length;
        int length = 1; // 新长度,同时记录上一个符合要求的位置
        int count = 1; // 重复次数
        int target = nums[0]; // 前一个不重复的数字
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == target) // 有重复的数字
            {
                count++; // 重复次数加1
                if (count <= 2) // 重复次数小于3
                {
                    length++;
                    nums[length - 1] = nums[i];
                }
            } else // 和前一个没有重复
            {
                target = nums[i];
                count = 1;
                length++;
                nums[length - 1] = nums[i];
            }
        }
        return length;
    }
}