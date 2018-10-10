class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //如果从i到j不能到达，那么应该从j+1位置开始，因为小车使用i位置的油都不能达到，那么中间任何位置也不可能到达
        int i = 0;
        int tank = 0; //油箱
        int all = 0;
        for(int j = 0;j<gas.size();j++)
        {
            if((tank += gas[j] - cost[j]) < 0)
            {
                i = j + 1;  //从j+1开始
                all += tank;
                tank = 0;
            }
        }
        return (all + tank) < 0 ? -1 : i;
    }
};