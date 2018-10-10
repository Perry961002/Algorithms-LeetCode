static const auto ban_io_sync = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    /*
    * 证明：将数字组合成最大数具有贪心性质
    * 证：设 S = s0,s1,...,sk-1,sk,sk+1,sk+2,...,sn-1是最大数，其中sk,sk+1不满足下述的贪心法，即 sk + sk+1 < sk+1 + sk
    * 但是 (s0+s1+...+sk-1)*10^(n-k) + (sk + sk+1)*10^(n-k-2) + (sk+2 +...+ sn-1) 小于
    *      (s0+s1+...+sk-1)*10^(n-k) + (sk+1 + sk)*10^(n-k-2) + (sk+2 +...+ sn-1)
    * 与S是最大解矛盾，所以贪心法可以得到最大解
    */
    static bool cmp(string& s1, string& s2)
    {
        //判断两个数字谁在前组合之后的数字更大
        return s1 + s2 > s2 + s1;
    }
    string largestNumber(vector<int>& nums) {
        string result;  //结果
        vector<string> rec( nums.size() );
        bool allzero = true;  //判断是不是全0
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] != 0)
                allzero = false;
            rec[i] = to_string(nums[i]);
        }
        if(allzero)
            return "0";
        sort(rec.begin(),rec.end(),cmp);
        for(int i=0;i<nums.size();i++)
            result += rec[i];
        return result;
    }
};