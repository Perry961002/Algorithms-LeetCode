class Solution {
public:
    string convertToTitle(int n) {
        //26进制
        string result;
        while(n)
        {
            //因为下标从1开始，所以n-1
            result = (char)((n-1) % 26 + 'A') + result;
            n = (n-1) / 26;
        }
        return result;
    }
};