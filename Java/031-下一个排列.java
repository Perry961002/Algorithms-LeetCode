import java.util.*;

class Solution {
    public void nextPermutation(int[] nums) {
        int len = nums.length; // 长度
        int i = len - 2; // 寻找第一个降序的数
        int j = len - 1; // 寻找第一个比降序的数大的数
        while (i >= 0 && nums[i] >= nums[i + 1])
            --i; // 寻找第一个降序的数
        if (i >= 0) {
            while (nums[j] <= nums[i])
                --j; // 寻找第一个大于nums[i]的数
            int tmp = nums[i];// 交换这两个数
            nums[i] = nums[j];
            nums[j] = tmp;
        }
        for (int start = i + 1, end = nums.length - 1; start < end; start++, end--) {
            int temp = nums[end];
            nums[end] = nums[start];
            nums[start] = temp;
        }
    }
}