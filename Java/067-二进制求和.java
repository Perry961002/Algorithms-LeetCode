class Solution {
    public String addBinary(String a, String b) {
        // 0 + 0 = 0, 0 + 1 = 1, 1 + 0 = 1, 1 + 1 = 10
        String sum = "";
        int carry = 0;// 进位
        int i = a.length() - 1, j = b.length() - 1;
        while (i >= 0 || j >= 0 || carry == 1) {
            if (i >= 0)
                carry += a.charAt(i--) - '0';
            if (j >= 0)
                carry += b.charAt(j--) - '0';
            sum = sum + carry % 2;
            carry /= 2;

        }
        return new StringBuffer(sum).reverse().toString();
    }
}