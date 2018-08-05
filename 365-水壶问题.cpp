class Solution {
public:
    int gcd(int x, int y)
    {
        return y == 0 ? x : gcd(y, x%y);
    }
    bool canMeasureWater(int x, int y, int z) {
        //z就是x和y的最大公约数的倍数，z<=x+y
        if(z == 0)
            return true;
        if(z > x + y)
            return false;
        return z % gcd(x, y) == 0;
    }
};