class Solution {
public:
    /*
    **组合数 C(n,k) = (n-k+1)*C(n,k-1)/k
    */
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i=0;i<numRows;i++)
        {
            vector<int> rec;
            rec.push_back(1);
            for(int j=1;j<=i;j++)
                rec.push_back((i-j+1)*rec[j-1]/j);
            result.push_back(rec);
        }
        return result;
    }
};