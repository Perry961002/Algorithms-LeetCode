class Solution {
public:
    //一开始想到了模拟，但是因为旋转和求和是有规则的，所以列出式子后规律也出来了
    //首先Bk : Bk[0],Bk[1],...,Bk[n-2],Bk[n-1]
    //***Bk+1 : Bk[n-1],Bk[0],...,Bk[n-2]
    //则F(k+1) - F(k) = Bk[0] + Bk[1] + ... + Bk[n-2] - (n-1) * Bk[n-1]
    //F(k+1) = F(k) + SUM(A) - n * Bk[n-1]
    int maxRotateFunction(vector<int>& A) {
        int n = A.size();
        if(n == 0)
            return 0;
        int sumA = 0, sumF = 0;
        for(int i=0;i<n;i++)
        {
            sumA += A[i]; //SUM(A)
            sumF += i * A[i];
        }
        int maxSum = sumF;
        for(int i=n-1;i>=0;i--)
        {
            sumF += sumA - n * A[i];//F(k+1) = F(k) + SUM(A) - n * Bk[n-1]
            maxSum = max(maxSum, sumF);
        }
        return maxSum;
    }
};