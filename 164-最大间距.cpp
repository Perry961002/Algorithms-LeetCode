class Solution {
public:
    int maximumGap(vector<int>& nums) {
        /*
        *直观想法，先用sort排序，再遍历数组找最大间距，O(n*logn)
        * 95.83%击败率
        ///
        if(nums.empty() || nums.size() == 1)
            return 0;
        sort(nums.begin(),nums.end());
        int max_result = 0;
        for(int i=1;i<nums.size();i++)
            max_result = max(max_result,nums[i] - nums[i-1]);
        return max_result;
        */
        /*
        *使用桶排序算法
        * 对于N个待排数据，M个桶，平均每个桶[N/M]个数据的桶排序平均时间复杂度为：
               O(N)+O(M*(N/M)*log(N/M))=O(N+N*(logN-logM))=O(N+N*logN-N*logM)
          当N=M时，即极限情况下每个桶只有一个数据时。桶排序的最好效率能够达到O(N)
        *假设有数组x[1...n]，其中最大的元素为max，最小元素为min，将左闭右开的实数区间[min，max)划分为n-1个等长的子区间（桶），每个子区间也是左闭右开的，          我们用len来表示每个子区间的长度。除去max和min，剩下的n-2个数，每个数都属于其中一个桶。对于同一个桶的两个数，因为桶是左闭右开的，所以他们的距离肯          定是小于len的。然后，关键的一点是，n-2个数放进n-1个桶，由抽屉原理可以知道，肯定有一个桶是空的，所以，距离最远的相邻的两个数，肯定是属于两个不同的          桶。于是，我们可以把每个桶都扫描一次，相邻最远的两个数，必定其中一个是某个桶里的最大值，另一个是另一个桶里的最小值
        *100%击败率
        */
        if(nums.size() < 2) return 0;  //排除空和只有一个元素的情况
        int min_num = INT_MAX;
        int max_num = INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            min_num = min(min_num , nums[i]);  //求最小值
            max_num = max(max_num , nums[i]);  //求最大值
        }
        double gap = (max_num - min_num)*1.0/(nums.size() - 1);  //最大差值
        if( gap == 0) return 0;
        int bucket_num = (int)((max_num - min_num)/gap);  //桶的个数
        vector<int> bucket_min(bucket_num,INT_MAX);  //桶的最小值
        vector<int> bucket_max(bucket_num,INT_MIN);   //桶的最大值
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] > min_num && nums[i] < max_num)
            {
                int index = (nums[i] - min_num)/gap;
                bucket_min[index] = min(bucket_min[index],nums[i]);
                bucket_max[index] = max(bucket_max[index],nums[i]);
            }
        }
        int maxgap = 0;  //相邻元素的最大差值
        int temp = min_num;   //前一个桶中的最大值
        for(int i=0;i<bucket_num;i++)
        {
            if(bucket_min[i] !=INT_MAX && bucket_max[i] != INT_MIN)  //排除空桶
            {
                maxgap = max(maxgap , bucket_min[i] - temp);
                temp = bucket_max[i];
            }
        }
        maxgap = max(maxgap , max_num - temp);   //算最大值与最后一个桶的差值
        return maxgap;
    }
};