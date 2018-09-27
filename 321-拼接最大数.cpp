class Solution {
public:
    //贪心法取得nums中长度为k的最大子数组
    vector<int> getMaxArray(vector<int> &nums, int k){
	    vector<int> res(k, 0);
	    if (k == 0)
		    return res;
	    int j = 0;
	    int len = nums.size();
	    for (int i = 0; i<len; i++){
		    //出栈操作(栈中有元素,nums中剩余元素比需要的元素多,nums[i]大于栈顶元素)
		    while (j > 0 && len - i > k - j && nums[i] > res[j - 1])
			    j--;
		    //入栈
		    if (j < k)
			    res[j++] = nums[i];
	    }
	    return res;
    }
    
    //贪心法将两个数组合并成最大数
    vector<int> mergeMaxArray(vector<int>& nums1, vector<int>& nums2){
	    int len1 = nums1.size(), len2 = nums2.size();
	    vector<int> res(len1 + len2, 0);
	    int k = 0;
		//每次取两个数组头元素最大的一个
		while(nums1.size() + nums2.size() > 0){            
            vector<int>& tem = nums1 > nums2 ? nums1 : nums2;
            res[k++] = tem[0];            
            tem.erase(tem.begin());        
        }
        return res;
    }

    //从nums1中取i个元素,从nums2中取
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> result(k, 0);
        int len1 = nums1.size(), len2 = nums2.size();
        for(int i = max(k - len2, 0); i <= min(k, len1); i++){
            cout<<i;
            vector<int> res1 = getMaxArray(nums1, i);
            vector<int> res2 = getMaxArray(nums2, k - i);
            vector<int> res = mergeMaxArray(res1, res2);
            result = max(result, res);
        }
        return result;
    }
};