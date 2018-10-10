class Solution {
public:
    int maximumSwap(int num) {
        if(num <= 10)
            return num;
        //出现的最大数,最大数的下标,当前数的下标,需要被交换两数的下标
        int maxNum = 0, maxIdx = 0, idx = 0, swapIdx1 = 0, swapIdx2 = 0;
        vector<int> array;
        while(num > 0){
            int now = num % 10;
            array.push_back(now);
            //出现了更大的数
            if(now > maxNum){
                maxNum = now;
                maxIdx = idx;
            }
            //更新两个下标
            else if(now < maxNum){
                swapIdx1 = idx;
                swapIdx2 = maxIdx;
            }
            idx ++;
            num /= 10;
        }
        //交换两个数
        swap(array[swapIdx1], array[swapIdx2]);
        int res = 0;
        for(int i=array.size()-1;i>=0;i--)
            res = res * 10 + array[i];
        return res;
    }
};