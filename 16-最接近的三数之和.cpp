class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort( nums.begin(),nums.end() );
        int len = nums.size();
        int min = 0X7F7F;
        for(int k=0;k<len-2;k++)
        {
            int i = k + 1;int j = len -1;
            while( i < j )
            {
                int sum = nums[i] + nums[j] + nums[k];
                if( abs(min - target) > abs(sum - target) )
                    min = sum;
                if( sum <= target )
                    i++;
                if( sum > target )
                    j--;
            }
        }
        return min;
    }
};