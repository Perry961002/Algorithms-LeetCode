static const auto ban_io_sync = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    //如果i位置比i-1位置要大，那么i位置的糖果数比前面的要加1
    //后来发现如果i位置的评分比两边的都大，那么应该i的糖果数应该是两边较大的一个+1
    //第一次扫描计算与前面比，第二次与后面比
    int candy(vector<int>& ratings) {
        if(ratings.size() == 0)
            return 0;
        vector<int> count(ratings.size(),1);
        for(int i = 1;i<ratings.size();i++)
            if(ratings[i] > ratings[i - 1])
                count[i] = count[i - 1] + 1;
        int mincandy = 0;
        for(int i = ratings.size()-1;i>0;i--)
        {
            if(ratings[i] < ratings[i - 1])
                count[i - 1] = max(count[i] + 1,count[i - 1]);
            mincandy += count[i];
        }
        mincandy += count[0];
        return mincandy;
    }
};