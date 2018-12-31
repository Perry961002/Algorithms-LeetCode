import java.util.*;
import java.util.stream.Collectors;

class Solution {
    public List<List<Integer>> result;

    public void per(int[] nums, int start) {
        if (start == nums.length - 1) {
            result.add(Arrays.stream(nums).boxed().collect(Collectors.toList()));
        } else {
            for (int i = start; i < nums.length; i++) {
                int tmp = nums[start];
                nums[start] = nums[i];
                nums[i] = tmp;
                per(nums, start + 1);
                tmp = nums[start];
                nums[start] = nums[i];
                nums[i] = tmp;
            }
        }
    }

    public List<List<Integer>> permute(int[] nums) {
        result = new ArrayList<>();
        if (nums.length == 0) {
            result.add(Arrays.stream(nums).boxed().collect(Collectors.toList()));
            return result;
        }
        per(nums, 0);
        return result;
    }
}