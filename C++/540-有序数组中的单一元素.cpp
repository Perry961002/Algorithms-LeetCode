class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        while(left < right)
        {
            int mid = (left+right)/2;
            //如果mid前面有偶数个数,nums[mid] == nums[mid-1],则前面剩余奇数个数，所以单独的数肯定在前面
            //其他情况可以类比证明
            if(nums[mid] == nums[mid+1])
            {              
                if(mid % 2 == 0)
                    left = mid + 2;
                else
                    right = mid -1;                  
            }
            else if(nums[mid] == nums[mid-1])
            {
                if((mid) % 2 == 0)
                    right = mid - 2;
                else
                    left = mid + 1;    
            }
            else
                return nums[mid];
        }
        return nums[left];

    }
};