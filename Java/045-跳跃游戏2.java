class Solution {
    public int jump(int[] nums) {
        int index = 0, maxLen = 0, count = 0;
        for (int i = 0; i < nums.length; i++) {
            if (i > index) // 当前位置超过了覆盖的下标
            {
                index = maxLen; // 覆盖下标更新到最远位置
                count++; // 步数加一
            }
            maxLen = Math.max(maxLen, i + nums[i]);
        }
        return count;
    }
}