class Solution {
public:
    //在两个数组中找到第K小的数
    int findKth(vector<int>& nums1, vector<int>& nums2, int start1, int start2, int k){
        int len1 = nums1.size(), len2 = nums2.size();
        int half = k / 2 - 1;
        
        //其中一个数组已经搜完,在另一个数组里搜索
        if(start1 >= len1)
            return nums2[start2 + k -1];
        if(start2 >= len2)
            return nums1[start1 + k -1];
        
        //k为1，则直接返回两个数组的最小数
        if(k == 1)
            return min(nums1[start1], nums2[start2]);
        int key1 = start1 + half >= len1 ? INT_MAX : nums1[start1 + half];
        int key2 = start2 + half >= len2 ? INT_MAX : nums2[start2 + half];
        
        if(key1 > key2)
            return findKth(nums1, nums2, start1, start2 + k / 2, k - k / 2);
        else
            return findKth(nums1, nums2, start1 + k / 2, start2, k - k / 2);
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        if(len % 2 == 0)
            return (findKth(nums1, nums2, 0, 0, len / 2) + findKth(nums1, nums2, 0, 0, len / 2 + 1) ) / 2.0;
        else
            return findKth(nums1, nums2, 0, 0, len / 2 + 1);
    }
};