class Solution {
    public int removeDuplicates(int[] nums) {
        int len = nums.length;
        if (len < 2)
            return len;
        int index = 0;// 前一个不一样的数的下标
        for (int i = 1; i < len; i++) {
            if (nums[i] != nums[index]) {
                index++;// 下标后移
                nums[index] = nums[i];
            }
        }
        return index + 1;
    }
}