class Solution {
    public int[] plusOne(int[] digits) {
        int carry = 1;
        int i = digits.length - 1;
        while (i >= 0 && carry > 0) {
            int sum = digits[i] + carry;
            carry = sum / 10;
            digits[i] = sum % 10;
            --i;
        }
        if (carry > 0) {
            int[] newArray = new int[digits.length + 1];
            System.arraycopy(digits, 0, newArray, 1, digits.length);
            newArray[0] = carry;
            return newArray;
        }
        return digits;
    }
}