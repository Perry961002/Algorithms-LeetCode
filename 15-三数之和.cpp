class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());   //先排序，后面可以进行排除
        vector<vector<int>> rec;   //解集
        int len = nums.size();  //长度
        for(int i=0;i<len;i++)
        {
            if(nums[i]>0) break;   //当前数>0，结束
            if(i>0&&nums[i]==nums[i-1]) continue;    //和前面一个有重复，从不重复的开始
            int target = 0-nums[i];  //下一次的目标值
            int m = i+1;int n = len-1;  // 从两个方向开始搜索 一正一负
            while(m<n)   //寻找另外两个数
            {
                if(nums[m]+nums[n] == target)  //找到解
                {
                    rec.push_back({nums[i],nums[m],nums[n]});
                    while(m<n&&nums[m]==nums[m+1]) ++m;   //避免重复
                    while(m<n&&nums[n]==nums[n-1]) --n;
                    ++m;
                    --n;
                }
                else if(nums[m]+nums[n] > target)
                    --n;
                else
                    ++m;
            }
        }
        return rec;
    }
};