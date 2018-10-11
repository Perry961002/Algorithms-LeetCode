class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> cards(nums.begin(), nums.end());
        return canGet(cards);
    }
    bool canGet(vector<double>& cards) {
        if (cards.size() == 0)
            return false;
        if (cards.size() == 1)
            return abs(cards[0] - 24) < 1e-6;
        
        for (int i = 0; i < cards.size(); i++) {
            for (int j = 0; j < cards.size(); j++) {
                //不能和自己运算
                if (i == j)
                    continue;
                //把cards中其他位置的数拷贝一份
                vector<double> tmpCards;
                for (int k = 0; k < cards.size(); k++)
                    if (k != i && k != j)
                        tmpCards.push_back(cards[k]);
                
                // '+','*','-','/'
                for (int k = 0; k < 4; k++) {
                    //因为i在外层,如果 j < i的话cards[i]和cards[j]之前已经算过一次,但'-'和'/'对操作数次序敏感
                    //所以这两个运算要再算
                    if (k < 2 && j < i)
                        continue;
                    if (k == 0) tmpCards.push_back(cards[i] + cards[j]);
                    else if (k == 1) tmpCards.push_back(cards[i] * cards[j]);
                    else if (k == 2) tmpCards.push_back(cards[i] - cards[j]);
                    else if (cards[j] == 0) continue;
                    else tmpCards.push_back(cards[i] / cards[j]);
                    
                    if (canGet(tmpCards))
                        return true;
                    
                    tmpCards.pop_back();
                }
            }
        }
        
        return false;
    }
};