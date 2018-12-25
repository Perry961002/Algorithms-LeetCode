import java.util.Hashtable;
class Solution {
	public int[] twoSum(int[] nums, int target) {
        Hashtable<Integer,Integer> num = new Hashtable<Integer,Integer>();
        for (int i = 0; i < nums.length; i++)
        {
            if (num.containsKey(target - nums[i]))
            {
                return new int[] {i, num.get(target - nums[i])};
            }
            num.put(nums[i], i);
        }
        return null;
    }
};