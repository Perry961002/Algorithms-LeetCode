public class Solution {
    int[] nums;
    List<List<Integer>> result;

    public void find(int index, List<Integer> last) {
        if (index >= nums.length)
            return;
        ArrayList<Integer> item = new ArrayList<Integer>();
        item.addAll(last);
        item.add(nums[index]);
        result.add(item);
        find(index + 1, last);
        find(index + 1, item);

    }

    public List<List<Integer>> subsets(int[] nums) {
        Arrays.sort(nums);
        this.nums = nums;
        this.result = new ArrayList<List<Integer>>();
        int i = 0;
        ArrayList<Integer> tmp = new ArrayList<Integer>();
        result.add(tmp);
        find(i, tmp);
        return result;

    }
}