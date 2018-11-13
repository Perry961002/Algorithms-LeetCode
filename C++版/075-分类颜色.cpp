/*
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> rec(3,0);  //分别统计0,1,2的个数
        for(int i=0;i<nums.size();i++)
            rec[nums[i]]++;
        int j = 0;
        for(int i=0;i<3;i++)
        {
            while( rec[i]>0 )
            {
                nums[j++] = i;
                rec[i]--;
            }
        }
    }
};
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        //start表示0结束的下标,end表示2开始的下标
        int start = 0, end = nums.size() - 1;
        //注意结束条件,是end
        for(int i = 0;i <= end; ++i){
            //把0放前面
            if(nums[i] == 0){
                swap(nums[i], nums[start]);
                ++start;
            }
            //把2放后面
            else if(nums[i] == 2){
                swap(nums[i], nums[end]);
                --end;
                --i;//需要检查交换过去的数
            }
        }
    }
};