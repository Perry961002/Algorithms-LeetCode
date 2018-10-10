class Solution {
public:
    /*
    *算n/2;(n是负数的话最后取倒数)
    *可以整除的话平方前面的值，不可以的话平方后在乘上原来的
    */
    double myPow(double x, int n) {
        double rec = 1.0;
        for(int i=n;i!=0;i/=2)
        {
            if( i%2 != 0 )
                rec*=x;
            x*=x;
        }
        return n<0 ? 1/rec : rec;
    }
};