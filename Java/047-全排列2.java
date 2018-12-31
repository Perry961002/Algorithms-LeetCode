import java.util.*;
import java.util.stream.Collectors;

class Solution {
    List<List<Integer>> res;

    void permute(int[] nums, int start) {
        if (start >= nums.length) {
            List<Integer> resElement = Arrays.stream(nums).boxed().collect(Collectors.toList());
            for (int i = 0; i < res.size(); i++) {
                if (res.get(i).equals(resElement))
                    return;
            }
            res.add(resElement);
        }
        for (int i = start; i < nums.length; ++i) {
            if (i != start && nums[i] == nums[start])
                continue;
            int tmp = nums[start];
            nums[start] = nums[i];
            nums[i] = tmp;
            permute(nums, start + 1);
            tmp = nums[start];
            nums[start] = nums[i];
            nums[i] = tmp;
        }
    }

    public List<List<Integer>> permuteUnique(int[] nums) {
        res = new ArrayList<>();
        permute(nums, 0);
        return res;
    }
}