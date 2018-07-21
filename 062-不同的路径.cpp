class Solution {
public:
    /*
    *因为只能向下或者向右，所以就只有m-1个下步，n-1个右步，只要确定了其中一种的位置就行，所以就等于C(m+n-2,n-1)
    */
    int uniquePaths(int m, int n) {
        if(m>n) swap(m,n); //选小的数
        int result = 1; //初始化
        for(int i=1;i<=m-1;i++)
        {
            result = (long int)(m+n-1-i)*result/i;
        }
        return result;
    }
};