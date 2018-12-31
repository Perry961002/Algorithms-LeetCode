class Solution {
    public String multiply(String num1, String num2) {
        String result = "";
        int carry = 0; // 进位
        int len1 = num1.length(), len2 = num2.length();
        int len = len1 + len2;
        int[] num = new int[len];
        for (int i = 0; i < len1; i++)
            for (int j = 0; j < len2; j++)
                num[len - 2 - i - j] += (num1.charAt(i) - '0') * (num2.charAt(j) - '0');
        for (int i = 0; i < len; i++) {
            num[i] += carry;
            carry = num[i] / 10; // 进位
            num[i] %= 10;
        }
        int i = len - 1;
        while (i > 0 && num[i] == 0)
            i--; // 两数相乘时位数可能不等于两个的和，所以去掉后面的0
        if (i < 0)
            return "0";
        while (i >= 0)
            result += "" + num[i--];
        return result;
    }
}