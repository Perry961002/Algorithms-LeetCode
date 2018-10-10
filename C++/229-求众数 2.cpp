class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //Boyer-Moore Majority Vote algorithm
        //每次删除三个不相同的数，最后留下的一定是出现次数超过1/3的数
        int num1, num2;
        int counter1 = 0, counter2 = 0;
        for(int i=0;i<nums.size();i++){
            if(num1 == nums[i])
                counter1++;
            else if(num2 == nums[i])
                counter2++;
            else if(counter1 == 0){
                counter1++;
                num1 = nums[i];
            }
            else if(counter2 == 0){
                counter2++;
                num2 = nums[i];
            }
            else{
                counter1--;
                counter2--;
            }
        }
        //验证
        vector<int> res;
        counter1 = 0;
        counter2 = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == num1)
                counter1++;
            else if(nums[i] == num2)
                counter2++;
        }
        if(counter1 > (nums.size() / 3))
            res.push_back(num1);
        if(counter2 > (nums.size() / 3))
            res.push_back(num2);
        return res;
    }
};