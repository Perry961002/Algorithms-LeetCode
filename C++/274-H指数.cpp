class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty())
            return 0;
        sort(citations.begin(), citations.end());  //先排序
        //因为至多有 h 篇论文，分别被引用了至少 h 次，所以h位置及之后位置的数都应该>=h
        int len = citations.size();
        for(int i = 0;i < citations.size();i++)
        {
            if(citations[i] >= len - i)
                return len - i;
        }
        return 0;  //特殊情况输入[0]
    }
};