class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int> > dp;//记录到达每个位置的所有步长
        //初始化
        for(int stone : stones){
            dp[stone] = {};
        }
        dp[0].insert(0);
        //遍历每个位置
        for(int stone : stones){
            //遍历所有的前驱
            for(int lastJump : dp[stone]){
                //三种跳跃步长
                for(int jumpSize = lastJump - 1; jumpSize <= lastJump + 1; jumpSize ++){
                    //下次跳到的位置有效
                    if(jumpSize > 0 && dp.count(stone + jumpSize)){
                        //记录下一个位置的信息
                        dp[stone + jumpSize].insert(jumpSize);
                    }
                }
            }
        }
        //最后一个位置有前驱位置返回true
        return !dp[stones.back()].empty();
    }
};