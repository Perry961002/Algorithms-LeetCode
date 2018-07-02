class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> rec;
        rec.push_back(1);
        for(int i=1;i<=rowIndex;i++)
            rec.push_back((long int)(rowIndex-i+1)*rec[i-1]/i);
        return rec;
    }
};