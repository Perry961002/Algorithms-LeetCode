class Solution:
    def findKth(self, nums1, m, nums2, n, k):
        if m < n:
            return self.findKth(nums2, n, nums1, m, k)
        if n == 0:
            return nums1[k-1]
        if k == 1:
            return min(nums1[0], nums2[0])
        p2 = min(k // 2, n)
        p1 = k - p2
        #比较两部分的最大值
        if nums1[p1-1] == nums2[p2-1]:
            return nums1[p1-1]
        #nums1的前p1个最大值更小
        if nums1[p1-1] < nums2[p2-1]:
            return self.findKth(nums1[p1:], m-p1, nums2, n, k-p1)
        else:
            return self.findKth(nums1, m, nums2[p2:], n-p2, k-p2)
        
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        len1 = len(nums1)
        len2 = len(nums2)
        if (len1+len2) % 2 == 0:
            return (self.findKth(nums1, len1, nums2, len2, (len1+len2) // 2) + self.findKth(nums1, len1, nums2, len2, (len1+len2) // 2 + 1)) / 2
        else:
            return self.findKth(nums1, len1, nums2, len2, (len1+len2) // 2 + 1)