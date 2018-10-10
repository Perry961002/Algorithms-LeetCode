class Solution {
public:
    //即求出砖缝次数最多的垂线
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> hash;
        int maxNum = 0;
        for(int i=0;i<wall.size();i++)
        {
            int lenSum = 0;//记录每层中每个砖缝处的累计长度
            //因为不能从左右边缘走，所以j<wall[i].size()-1
            for(int j=0;j<wall[i].size()-1;j++)
            {
                lenSum += wall[i][j];
                hash[lenSum] ++;//这个缝出现的次数
            }
        }
        for(auto it : hash)
            maxNum = max(maxNum, it.second);
        return wall.size() - maxNum;
    }
};