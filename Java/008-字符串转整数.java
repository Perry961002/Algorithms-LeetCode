class Solution {
    public int myAtoi(String str) {
        byte[] arr = str.getBytes();
        if (arr.length == 0)
            return 0;
        long result = 0;// 因为要比较是不是溢出，所以用长整型
        int flag = 1;// 判断是不是负数
        int j = 0;
        while (j < arr.length && arr[j] == ' ')
            j++;
        if (j < arr.length) {
            if (arr[j] == '-') {
                flag = -1;
                j++;
            } else if (arr[j] == '+')
                j++;
        }
        for (int i = j; i < arr.length; i++) {
            if (result > Integer.MAX_VALUE) {
                if (flag == 1)
                    return (int) (Integer.MAX_VALUE);
                else if (flag == -1)
                    return (int) (Integer.MAX_VALUE + 1) * -1;
            }
            if (arr[i] >= '0' && arr[i] <= '9') {
                result = result * 10 + arr[i] - '0';
            } else {
                break;
            }
        }
        if (result > Integer.MAX_VALUE) {
            if (flag == 1)
                return (int) (Integer.MAX_VALUE);
            else if (flag == -1)
                return (int) (Integer.MAX_VALUE + 1) * -1;
        }
        return (int) (result * flag);
    }
}