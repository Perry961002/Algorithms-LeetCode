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