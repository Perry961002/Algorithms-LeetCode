class Solution {
public:
    /*
    *          1  2  3
    *          4  5  6
    * ______ *___________
    *         6  12  18
    *      5 10  15
    *   4  8 12
    *_+__________________
    *   4 13 28  27  18
    *_4+1_3+3_8+2_7+1_8__
    *   5 6  0   8   8
    *
    */
    string multiply(string num1, string num2) {
        string result = ""; int carry = 0;  //进位
        int len1 = num1.size() , len2 = num2.size();
        int len = len1 +len2;
        vector<int> num(len , 0);
        for(int i=0;i<len1;i++)
            for(int j=0;j<len2;j++)
                num[len - 2 -i -j] += (num1[i] - '0') * (num2[j] - '0');
        for(int i=0;i<len;i++)
        {
            num[i] += carry;
            carry =num[i]/10; //进位
            num[i] %=10;
        }
        int i = len -1;
        while(num[i]==0) i--;   //两数相乘时位数可能不等于两个的和，所以去掉后面的0
        if(i<0) return "0";
        while(i>=0) result += num[i--] + '0';
        return result;
    }
};