class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        //因为只是加1，只有每一位上都是9，才会产生进位而且是10的幂
        for(int i=digits.size()-1;i>=0;i--)
        {
            if(digits[i] < 9)
            {
                digits[i] ++;
                return digits;
            }
            else
            {
                if(i>0)
                    digits[i] = 0;// 9 + 1 = 10
                else//i == 0
                {
                    digits[0] = 1;
                    digits.push_back(0);
                    return digits;
                }
            }
        }
    }
};