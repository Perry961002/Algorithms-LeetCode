class Solution {
    public int removeElement(int[] nums, int val) {
        // 遍历数组,发现和val相等,则用最后一项替代他,并且检测
        int move = 0;
        for (int i = 0; i < nums.length - move; i++) {
            if (nums[i] == val) {
                move++;
                nums[i] = nums[nums.length - move];
                i--;// 退回去检测被替代之后的数
            }
        }
        return nums.length - move;
    }
}