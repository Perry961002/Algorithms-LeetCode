class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //B-M投票法
        //成对删除不一样的数
        int element = 0, count = 0;
        for(int i=0;i<nums.size();i++){
            //初始化
            if(count == 0){
                element = nums[i];
                count = 1;
            }
            else{
                if(element == nums[i])
                    count++;
                else
                    count--;//成对删除
            }
        }
        return element;
    }
};