class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res = arr;
        while (res.size() > k)
        {
            int left = abs(res[0]-x);
            int right = abs(res.back() - x);
            if (left > right)
                res.erase(res.begin());
            else
                res.pop_back();
        }
        return res;
    }
};