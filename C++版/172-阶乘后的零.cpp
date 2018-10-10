class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;
        while(n)  //找5的个数
        {
            result += n/5;
            n /= 5;
        }
        return result;
    }
};