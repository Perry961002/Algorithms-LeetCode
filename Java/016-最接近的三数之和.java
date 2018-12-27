import java.util.Arrays;

class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int len = nums.length;
        int min = 0X7F7F;
        for (int k = 0; k < len - 2; k++) {
            int i = k + 1;
            int j = len - 1;
            while (i < j) {
                int sum = nums[i] + nums[j] + nums[k];
                if (Math.abs(min - target) > Math.abs(sum - target))
                    min = sum;
                if (sum <= target)
                    i++;
                if (sum > target)
                    j--;
            }
        }
        return min;
    }
}