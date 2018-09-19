class Solution {
public:
    struct cmp 
    {
        //自定义比较函数
        bool operator() (pair<int, int> &a, pair<int, int> &b) 
        {
            return a.first + a.second < b.first + b.second;
        }
    };
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;//建大根堆
        for (int i = 0; i < min((int)nums1.size(), k); i++) 
        {
            for (int j = 0; j < min((int)nums2.size(), k); j++) 
            {
                //下面维持一个大小为k的大根堆
                if (q.size() < k) 
                {
                    q.push({nums1[i], nums2[j]});
                }
                //堆的大小超过k了，如果当前的数值对的和比堆顶的和小，说明堆顶元素需要删除
                //比堆顶大的话就没必要加入堆
                else if ( (nums1[i] + nums2[j]) < (q.top().first + q.top().second) ) 
                {
                    q.push({nums1[i], nums2[j]}); 
                    q.pop();//删除最大的那个
                }
            }
        }
        while (!q.empty()) 
        {
            res.push_back(q.top()); 
            q.pop();
        }
        return res;
    }
};