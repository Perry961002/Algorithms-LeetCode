class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int result = 0;
        unordered_map<int,int> num;
        for(int i=0;i<A.size();i++)
            for(int j=0;j<B.size();j++)
                ++num[A[i]+B[j]];
        for(int i=0;i<A.size();i++)
            for(int j=0;j<B.size();j++)
            {
                int target = 0-(C[i]+D[j]);
                result += num[target];
            }
        return result;
    }
};