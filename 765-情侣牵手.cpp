class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int len = row.size();
        vector<int> couples(len, 0);//记录第i个人的位置
        int res = 0;
        //初始化
        for(int i=0;i<len;i++){
            couples[row[i]] = i;
        }
        for(int i=0;i<len;i += 2){
            //情侣已经挨着坐了
            if((row[i] / 2) == (row[i+1] / 2))
                continue;
            //找row[i]的情侣在哪
            int another = 0;
            if(row[i] % 2 == 0)
                another = couples[row[i] / 2 * 2 + 1];
            else
                another = couples[row[i] / 2 * 2];
            //原来i+1位置上的人被换到了another
            couples[row[i+1]] = another;
            //把row[i]的情侣放他旁边
            swap(row[i+1], row[another]);
            res++;
        }
        return res;
    }
};