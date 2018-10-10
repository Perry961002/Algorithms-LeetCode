class Solution {
public:
    int nthUglyNumber(int n) {
        int a[n];a[0]=1;
        int num2=0,num3=0,num5=0;
        for(int i=1;i<n;i++)
        {
            a[i]=min(min(a[num2]*2,a[num3]*3),a[num5]*5);  //顺序找出a[n]
            if(a[i]/a[num2]==2)
                num2++;
            if(a[i]/a[num3]==3)
                num3++;
            if(a[i]/a[num5]==5)
                num5++;
        }
        return a[n-1];
    }
};