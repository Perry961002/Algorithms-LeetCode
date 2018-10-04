class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        //动态规划,考虑公差只有一种的情况
        //假设已发现的等差数组的个数为N,累计长度为L,现在又发现一个数可以被添加进数组
        //那么新产生的数组个数为L + 1;则N = N + L + 1
        int result = 0, newNum = 0;
        for(int i=2;i<A.size();i++){
            //符合等差数列条件
            if(A[i] - A[i-1] == A[i-1] - A[i-2]){
                newNum ++;
                result += newNum;
            }
            else
                newNum = 0;
        }
        return result;
    }
};