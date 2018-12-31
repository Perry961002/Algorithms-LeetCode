import java.util.*;

class Solution {
    public int firstMissingPositive(int[] nums) {
        Arrays.sort(nums); // 先排序
        int result = 1; // 结果初始化为1
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] < 1)
                continue; // 找到第一个正数
            if (i >= 1 && nums[i] == nums[i - 1])
                continue; // 数组中相同的不看
            if (nums[i] == result) {
                result++; // 下一个没有找到的正数
            } else
                break;
        }
        return result;
    }
}